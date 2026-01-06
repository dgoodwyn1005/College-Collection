import numpy as np

def question1():
    ar1 = np.array([1,2,3,4,5,6,7,8,9,10])
    ar2 = np.array([[1,2,3], [4,5,6], [7,8,9]])

    print("Array 1")
    print(ar1.ndim) #Dimensions
    print(ar1.shape) #Shape
    print(ar1.dtype) #Data type
    print()
    print("Array 2")
    print(ar2.ndim) #Dimensions
    print(ar2.shape) #Shape
    print(ar2.dtype) #Data type
    print()

    print(ar1[2])
    print(ar2[1])
    print(ar2[0,2])

def question2():
    A = np.array([1,2,3,4,5])
    B = np.array([5,4,3,2,1])

    print(A + B) #Addition
    print(A - B) #Subtraction
    print(A * B) #Multiplication - Element wise
    print(A / B) #Division
    print(np.dot(A, B)) #Dot Product

def question3():
    array = np.array([1,2,3,4,5,6,7,8,9,10,11,12])
    print(array)
    array = array.reshape(3,4)
    print(array)

    a = array[0:2, 0:4] #First two rows
    b = array[:, -1] #Last column
    c = array[1:, 1:] #Sub-array contains rows 2-3 and columns 2-4
    print(a)
    print(b)
    print(c)

    array = array.flatten()
    print(array)

print("Question 1!")
question1()
print()

print("Question 2!")
question2()
print()

print("Question 3!")
question3()
print()
