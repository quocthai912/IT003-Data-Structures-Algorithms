def merge(array, left, mid, right):
    sizeLeft = (mid - left) + 1
    sizeRight = right - mid
    mangLeft = []
    mangRight = []
    for i in range(sizeLeft):
        mangLeft.append(array[i + left])
    for j in range(sizeRight):
        mangRight.append(array[mid + 1 + j])
    i = 0
    j = 0
    k = left
    while i < sizeLeft and j < sizeRight:
        if mangLeft[i] < mangRight[j]:
            array[k] = mangLeft[i]
            k += 1
            i += 1
        else:
            array[k] = mangRight[j]
            k += 1
            j += 1
    while i < sizeLeft:
        array[k] = mangLeft[i]
        k += 1
        i += 1
    while j < sizeRight:
        array[k] = mangRight[j]
        k += 1
        j += 1


def mergeSort(array, left, right):
    if left < right:
        mid = left + (right - left) // 2
        mergeSort(array, left, mid)
        mergeSort(array, mid + 1, right)
        merge(array, left, mid, right)


if __name__ == "__main__":
    size = int(input())
    array = [int(i) for i in input().split()]
    mergeSort(array, 0, len(array) - 1)
    for i in range(len(array)):
        print(array[i], end=" ")
