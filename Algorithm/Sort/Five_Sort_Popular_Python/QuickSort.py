def quickSort(array, left, right):
    if left < right:
        pivot = array[left + (right - left) // 2]
        i = left
        j = right
        while i < j:
            while array[i] < pivot:
                i += 1
            while array[j] > pivot:
                j -= 1
            if i <= j:
                array[i], array[j] = array[j], array[i]
                i += 1
                j -= 1
        quickSort(array, left, j)
        quickSort(array, i, right)


if __name__ == "__main__":
    size = int(input())
    array = [int(i) for i in input().split()]
    quickSort(array, 0, len(array) - 1)
    for i in range(len(array)):
        print(array[i], end=" ")
