def selectionSort(array):
    for i in range(len(array) - 1):
        minIndex = i
        for j in range(i + 1, len(array)):
            if array[j] < array[minIndex]:
                minIndex = j
        if array[i] > array[minIndex]:
            array[i], array[minIndex] = array[minIndex], array[i]


if __name__ == "__main__":
    size = int(input())
    array = [int(i) for i in input().split()]
    selectionSort(array)
    for i in range(len(array)):
        print(array[i], end=" ")
