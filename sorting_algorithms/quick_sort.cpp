#include <iostream>
#include <vector>

int partition(std::vector<int>&v, int left, int right)
{
  int pivot = v[right];

  int pId = left;

  for (int i = left; i < right; i++)
    {
      if (v[i] <= pivot)
      {
        std::swap(v[i], v[pId]);
        pId++;
      }
    }

  std::swap(v[pId], v[right]);
  
  return pId;
};

void quickSort(std::vector<int>&v, int left, int right)
{
  if (left >= right)
  {
    return;
  }

  int pivot = partition(v, left, right);

  quickSort(v, left, pivot - 1);
  quickSort(v, pivot + 1, right);
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

    quickSort(vec, 0, n - 1);

    for(int i = 0; i < n; i++)
    {
        std::cout << vec[i] << " ";
    }
    return 0;
}
