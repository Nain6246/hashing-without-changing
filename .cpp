// Hashing With Linear Probing
// Hashing without changing
#include <iostream>
#include <limits.h>

using namespace std;

void Insert(int ary[], int hFn, int Size)
{
   int element, pos, n = 0;

   cout << "Enter key element to insert\n";
   cin >> element;

   pos = element % hFn;

   while (ary[pos] != INT_MIN)
   {
      if (ary[pos] == INT_MAX)
         break;
      pos = (pos + 1) % hFn;

      n++;
      if (n == Size)
         break;
   }

   if (n == Size)
      cout << "Hash table was full of elements\nNo Place to insert this element\n\n";
   else
      ary[pos] = element;
}

void Delete(int ary[], int hFn, int Size)
{
   int element, n = 0, pos;

   cout << "Enter element to delete\n";
   cin >> element;

   pos = element % hFn;

   while (n++ != Size)
   {
      if (ary[pos] == INT_MIN)
      {
         cout << "Element not found in hash table\n";
         break;
      }
      else if (ary[pos] == element)
      {
         ary[pos] = INT_MAX;
         cout << "Element deleted\n\n";
         break;
      }
      else
      {
         pos = (pos + 1) % hFn;
      }
   }
   if (--n == Size)
      cout << "Element not found in hash table\n";
}

void Search(int ary[], int hFn, int Size)
{
   int element, position, n = 0;

   cout << "Enter element you want to search\n";
   cin >> element;

   position = element % hFn;

   while (n++ != Size)
   {
      if (ary[position] == element)
      {
         cout << "Element found at index " << position << "\n";
         break;
      }
      else if (ary[position] == INT_MAX || ary[position] != INT_MIN)
         position = (position + 1) % hFn;
   }

   if (--n == Size)
      cout << "Element not found in hash table\n";
}

void display(int ary[], int Size)
{
   int i;

   cout << "Index\tValue\n";

   for (i = 0; i < Size; i++)
      cout << i << "\t" << ary[i] << "\n";
}

int main()
{
   int Size, hFn, i, choice;

   cout << "Enter size of hash table\n";
   cin >> Size;

   int *arr = new int[Size];

   cout << "Enter hash function [if mod 10 enter 10]\n";
   cin >> hFn;

   for (i = 0; i < Size; i++)
      arr[i] = INT_MIN;
   do
   {
      cout << "Enter your choice\n";
      cout << " 1-> Insert\n 2-> Delete\n 3-> Display\n 4-> Searching\n 0-> Exit\n";
      cin >> choice;

      switch (choice)
      {
      case 1:
         Insert(arr, hFn, Size);
         break;
      case 2:
         Delete(arr, hFn, Size);
         break;
      case 3:
         display(arr, Size);
         break;
      case 4:
         Search(arr, hFn, Size);
         break;
      default:
         cout << "Enter correct choice\n";
      }
   } while (choice);

   return 0;
}
