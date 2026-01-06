import requests
from bs4 import BeautifulSoup
import re

# Predefined list of cities with coordinates
locations = {
    1: ("San Francisco", "37.7749,-122.4194"),
    2: ("Boston", "42.3601,-71.0589"),
    3: ("Washington DC", "38.8951,-77.0364"),
    4: ("Seattle", "47.6062,-122.3321"),
    5: ("Atlanta", "33.7490,-84.3880"),
    6: ("Miami", "25.7752,-80.2086"),
    7: ("New York", "40.6635,-73.9387"),
    8: ("Los Angeles", "34.0194,-118.4108"),
    9: ("Chicago", "41.8376,-87.6818"),
    10: ("Houston", "29.7866,-95.3909"),
    11: ("Phoenix", "33.5722,-112.0901"),
    12: ("Philadelphia", "40.0094,-75.1333"),
    13: ("San Antonio", "29.4724,-98.5251"),
    14: ("San Diego", "32.8153,-117.1350"),
    15: ("Dallas", "32.7933,-96.7665"),
    16: ("San Jose", "37.2967,-121.8189")
}

# Predefined business types
business_types = {
    1: "restaurant",
    2: "cafe",
    3: "gym",
    4: "bar",
    5: "pharmacy",
    6: "hotel",
    7: "library",
    8: "gas station",
    9: "supermarket",
    10: "barber"
}

def scrape_email_from_website(url):
    try:
        headers = {"User-Agent": "Mozilla/5.0"}
        response = requests.get(url, headers=headers, timeout=10)
        soup = BeautifulSoup(response.text, 'lxml')

        # Find all email patterns
        emails = set(re.findall(r"[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}", soup.text))
        if emails:
            return list(emails)[0]  # Return the first found
        return None
    except Exception as e:
        print(f"   ⚠️ Could not scrape email from {url}: {e}")
        return None

def find_local_businesses(api_key, location, keyword, radius=1500, small_business_only=False):
    url = "https://maps.googleapis.com/maps/api/place/nearbysearch/json"

    params = {
        "location": location,
        "radius": radius,
        "keyword": keyword,
        "key": api_key
    }

    response = requests.get(url, params=params)
    data = response.json()

    if data["status"] != "OK":
        print(f"\nError: {data['status']} - {data.get('error_message', '')}")
        return []

    businesses = []
    for place in data.get("results", []):
        name = place.get("name")
        address = place.get("vicinity")
        rating = place.get("rating", "N/A")
        place_id = place.get("place_id")
        business_status = place.get("business_status", "")

        if small_business_only and business_status != "OPERATIONAL":
            continue

        # Place Details API to get website
        details_url = "https://maps.googleapis.com/maps/api/place/details/json"
        details_params = {
            "place_id": place_id,
            "fields": "website",
            "key": api_key
        }

        details_response = requests.get(details_url, params=details_params).json()
        website = details_response.get("result", {}).get("website")

        # Try to scrape email if website exists
        email = scrape_email_from_website(website) if website else None

        businesses.append({
            "name": name,
            "address": address,
            "rating": rating,
            "website": website,
            "email": email
        })

    return businesses

def main():
    print("Welcome to the Local Business Finder with Email Scraper!\n")

    # Choose location
    print("Choose a location:")
    for key, (name, _) in locations.items():
        print(f"{key}. {name}")
    
    loc_choice = input("\nEnter the number of the city: ")
    if not loc_choice.isdigit() or int(loc_choice) not in locations:
        print("Invalid location choice.")
        return
    city_name, city_coords = locations[int(loc_choice)]

    # Choose business type
    print("\nChoose a business type:")
    for key, btype in business_types.items():
        print(f"{key}. {btype.capitalize()}")

    type_choice = input("\nEnter the number of the business type: ")
    if not type_choice.isdigit() or int(type_choice) not in business_types:
        print("Invalid business type choice.")
        return
    keyword = business_types[int(type_choice)]

    # Ask whether to show only small businesses
    small_only = input("\nOnly show small businesses? (y/n): ").lower().startswith('y')

    # Google API Key
    API_KEY = "AIzaSyARy9REj6w_IGfBVN9xd6V2xNS6Q8lVZxQ"  # 🔑 Replace with your actual API key

    print(f"\n🔍 Searching for {keyword}s near {city_name}...\n")
    results = find_local_businesses(API_KEY, city_coords, keyword, small_business_only=small_only)

    if results:
        for i, biz in enumerate(results, start=1):
            print(f"{i}. {biz['name']}")
            print(f"   Address: {biz['address']}")
            print(f"   Rating: {biz['rating']}")
            if biz['website']:
                print(f"   Website: {biz['website']}")
            if biz['email']:
                print(f"   📧 Email: {biz['email']}")
            print()
    else:
        print("No businesses found.")

if __name__ == "__main__":
    main()
