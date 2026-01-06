def read_training_data(file_name:str) -> list:
    train_file = open(file_name,'r')
    train_data = []
    for line in train_file:
        line = line.strip()
        line_list = line.split(",")
        if line_list[-1] == "2":
            line_list.insert(1, "b")
        else:
            line_list.insert(1, "m")
        line_list.pop()
        
        try:
            for n in range(2, len(line_list)):
                line_list[n] = int(line_list[n])
            train_data.append(tuple(line_list))
        except ValueError:
            pass
    train_file.close()
    return train_data

def compute_averages(train_data)->tuple:
    benign2 = [x[2] for x in train_data if x[1]=="b"]
    malignant2 = [x[2] for x in train_data if x[1]=="m"]
    benign3 = [x[3] for x in train_data if x[1]=="b"]
    malignant3 = [x[3] for x in train_data if x[1]=="m"]
    ba2 = sum(benign2)/len(benign2)
    ba3 = sum(benign3)/len(benign3)
    ma2 = sum(malignant2)/len(malignant2)
    ma3 = sum(malignant3)/len(malignant3)
    return ((ba2, ba3), (ma2, ma3))
    
def classify_data(train_data:list, threshold:float)->list:
    classified_data = []
    for item in train_data:
        if item[2] < threshold:
            result_tuple = (item[0], item[1], "b")
        else:
            result_tuple = (item[0], item[1], "m")
        classified_data.append(result_tuple)
    return classified_data

def score_classifier(classified_data:list)->tuple:
    correct = 0
    false_positive = 0
    false_negative = 0
    for item in classified_data:
        if item[1] == item[2]:
            correct += 1
        elif item[1] == "b" and item[2] == "m":
            false_positive += 1
        else:
            false_negative += 1
    return (correct, false_positive, false_negative)
    
train = read_training_data("fullTrainData.txt")
b, m = compute_averages(train)
threshold = ((b[0] + b[1]) + (m[0] + m[1])) / 2
classified = classify_data(train, threshold)
scored = score_classifier(classified)
print(scored)