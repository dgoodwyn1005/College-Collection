import numpy as np

arr1 = np.array([[1, 2, 3],[4, 5, 6],[7, 8, 9]])
arr2 = np.array([[1, 0],[0, -1]])

def convolution(image, kernel):
    kernel_height, kernel_width = kernel.shape
    image_height, image_width = image.shape

    final_height = image_height - kernel_height + 1
    final_width = image_width - kernel_width + 1

    finalConvolution = np.zeros((2, 2))

    for y in range(final_height):
        for x in range(final_width):
            region = image[y:y+kernel_height, x:x+kernel_width]
      
            finalConvolution[x, y] = np.sum(region * kernel)

    return finalConvolution


print(convolution(arr1, arr2))
