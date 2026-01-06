import math

#Fever/Chills, SoreThroat, Cough, Headache/BodyAche, Stuffy/RunnyNose, Fatigue, Fever, Diagnosis
table = [
    ["Mild", "yes", "moderate", "None", "yes", "mild", "None", "Cold"],
    ["Medium", "no", "extreme", "Severe", "no", "extreme", "higher", "Flu"],
    ["Extreme", "no", "none", "Moderate", "yes", "mild", "slight", "Flu"],
    ["No", "no", "mild", "Moderate", "yes", "none", "slight", "Cold"],
    ["Extreme", "yes", "moderate", "Severe", "no", "extreme", "higher", "Flu"],
    ["No", "yes", "moderate", "None", "yes", "none", "None", "Cold"],
    ["Medium", "no", "moderate", "Severe", "no", "extreme", "higher", "Flu"],
    ["No", "yes", "mild", "None", "no", "mild", "slight", "Cold"],
]

groups = [
    "Fever/Chills", "SoreThroat", "Cough", "Headache/BodyAche",
    "Stuffy/RunnyNose", "Fatigue", "Fever"
]

def entropy(data):
    label_counts = {}
    for row in data:
        label = row[-1]
        if label not in label_counts:
            label_counts[label] = 0
        label_counts[label] += 1

    total = len(data)
    ent = 0.0
    for count in label_counts.values():
        p = count / total
        ent -= p * math.log2(p)
    return ent

def info_gain(data, attr_index):
    total_entropy = entropy(data)
    subsets = {}
    for row in data:
        key = row[attr_index]
        if key not in subsets:
            subsets[key] = []
        subsets[key].append(row)

    subset_entropy = 0.0
    for subset in subsets.values():
        subset_entropy += len(subset) / len(data) * entropy(subset)

    return total_entropy - subset_entropy

def majority_class(data):
    label_counts = {}
    for row in data:
        label = row[-1]
        if label not in label_counts:
            label_counts[label] = 0
        label_counts[label] += 1

    return max(label_counts, key=label_counts.get)

def id3(data, groups):
    labels = [row[-1] for row in data]
    if labels.count(labels[0]) == len(labels):
        return labels[0]
    if not groups:
        return majority_class(data)

    gains = [info_gain(data, i) for i in range(len(groups))]
    best_attr_index = gains.index(max(gains))
    best_attr = groups[best_attr_index]

    tree = {best_attr: {}}
    values = set(row[best_attr_index] for row in data)
    for value in values:
        sub_data = [row[:best_attr_index] + row[best_attr_index+1:] for row in data if row[best_attr_index] == value]
        sub_groups = groups[:best_attr_index] + groups[best_attr_index+1:]
        tree[best_attr][value] = id3(sub_data, sub_groups)

    return tree

def tree_display(tree, indent=""):
    if isinstance(tree, dict):
        for attr, branches in tree.items():
            for value, subtree in branches.items():
                print(f"{indent}{attr} = {value}")
                tree_display(subtree, indent + "  ")
    else:
        print(f"{indent}Result: {tree}")

tree = id3(table, groups)
tree_display(tree)
