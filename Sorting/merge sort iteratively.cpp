#include<iostream>
using namespace std;
void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1], R[n2];

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1+ j];

	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}


void mergeSort(int arr[], int n)
{
    int st;
    int e;
    for (st=1; st<=n-1; st=2*st)
    {
        for (e=0; e<n-1; e+=2*st)
        {
            int mid = min(e + st - 1, n-1);
            int right = min(e + 2*st - 1, n-1);
            merge(arr, e, mid, right);
        }
    }
}

void Print(int ar[], int n)
{
	int i;
	for (i=0; i < n; i++)
    cout<<ar[i]<<" "<<endl;
}

int main()
{
	int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
	mergeSort(arr, n);
	Print(arr, n);
	return 0;
}
