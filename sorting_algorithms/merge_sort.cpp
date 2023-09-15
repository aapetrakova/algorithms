#include <iostream>
#include <vector>

//function that merges two parts of the vector in sorted order
void Merge(std::vector<int>&v, int left, int right)
{
    int mid = left + (right - left) / 2;  //middle of the vector
    int i = left, j = mid + 1;  //pointers for each part of the vector
    std::vector<int> d;  //auxiliary vector

    while (i <= mid && j <= right)
    {
        //compare the elements on which the pointers stand and add the smaller of them to d, moving the pointer
        if (v[i] <= v[j])
        {
            d.push_back(v[i]);
            i++;
        }
        else
        {
            d.push_back(v[j]);
            j++;
        }
    }

    //if after the pointer leaves the limits of one of the parts there are still elements left in the second, then add them to the end
    while (i <= mid)
    {
        d.push_back(v[i]);
        i++;
    }

    while (j <= right)
    {
        d.push_back(v[j]);
        j++;
    }


    //assign sorted values to the elements of the original vector
    for (i = 0; i < d.size(); i++)
    {
        v[left + i] = d[i];
    }
};

//sorted function
void MergeSort(std::vector<int>&v, int left, int right)
{
    //check if there are still elements left in the vector
    if (left < right) {
        //if there are 2 elements left then compare them and swap them if necessary
        if (right - left == 1)
        {
            if (v[left] > v[right])
            {
                std::swap(v[left], v[right]);
            }
        }
        //else divide the vector into 2 parts and process each of them
        else
        {
            MergeSort(v, left, left + (right - left) / 2);
            MergeSort(v, left + (right - left) / 2 + 1, right);
            Merge(v, left, right);
        }
    }
};

int main()
{
    int n, x;
    std::cin >> n;

    std::vector<int> vec;

    for(int i = 0; i < n; i++)
    {
        std::cin >> x;
        vec.push_back(x);
    }

    MergeSort(vec, 0, n - 1);

    for(int i = 0; i < n; i++)
    {
        std::cout << vec[i] << " ";
    }
    return 0;
}
