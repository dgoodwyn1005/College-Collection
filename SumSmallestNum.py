def sum_two_smallest_numbers(numbers):
    smallest = min(numbers[0], numbers[1])
    second_smallest = max(numbers[0], numbers[1])
    for n in range(2, len(numbers)):
        if numbers[n] < smallest:
            second_smallest = smallest
            smallest = numbers[n]
        elif numbers[n] < second_smallest:
            second_smallest = numbers[n]
    return smallest + second_smallest
            
lyst = [5,2,7,1]
result = sum_two_smallest_numbers(lyst)
print(result)