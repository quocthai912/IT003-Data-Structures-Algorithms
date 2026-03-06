def insertionSort(array):
    for i in range(1, len(array)):
        key = array[i]
        j = i - 1
        while j >= 0 and array[j] > key:
            array[j + 1] = array[j]
            j -= 1
        array[j + 1] = key


if __name__ == "__main__":
    size = int(input())
    array = [int(i) for i in input().split()]
    insertionSort(array)
    for i in range(len(array)):
        print(array[i], end=" ")
