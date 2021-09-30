#include "sorts.hpp"
#include "generators.hpp"
#include "sequence_list.hpp"
#include "ISorter.hpp"
#include "vectorSequence.hpp"

int main()
{
    const string MENU = "1. Bubble sort\n2. Cocktail sort\n3. Insertion sort\n4. Count sort\n5. Quick sort\n0. Exit\n";

    int choice = -1;
    int n = -1;

    vector<int> main_array; // массив с числами

    ISorter<int, Linked_List_Sequence<int>> sorter_for_list;
    ISorter<int, vectorSequence<int>> sorter_for_vector;


    while (choice != 0)
    {
        cout << MENU;
        cin >> choice;
        switch (choice)
        {
            case 1:
            {
                cout << "Input the length of the array: \n";
                cin >> n;
                main_array = ArrayGenerator(n).GenerateRandomArray();

                Linked_List_Sequence<int> list(main_array, static_cast<int>(main_array.size()));
                vectorSequence<int> vec(main_array);

                cout << "Do you want to compare arrays before the sorting ans after? (1-yes, 2-no)\n";
                int var;
                cin >> var;
                if (var == 1)
                {
                    cout << "For the list:\n";
                    list.print();
                    cout << "For the vector:\n";
                    vec.print();
                    cout << "\n\n";
                }

                sorter_for_list.bubble_sort(list, 0, list.getLength() - 1);
                sorter_for_vector.bubble_sort(vec, 0, list.getLength() - 1);

                if (var == 1)
                {
                    cout << "For the list:\n";
                    list.print();
                    cout << "For the vector:\n";
                    vec.print();
                    cout <<"\n\n";
                }
                list.isSorted();
                vec.isSorted();

                break;
            }
            case 2:
            {
                cout << "Input the length of the array: \n";
                cin >> n;
                main_array = ArrayGenerator(n).GenerateRandomArray();

                Linked_List_Sequence<int> list(main_array, static_cast<int>(main_array.size()));
                vectorSequence<int> vec(main_array);

                cout << "Do you want to compare arrays before the sorting ans after? (1-yes, 2-no)\n";
                int var;
                cin >> var;
                if (var == 1)
                {
                    cout << "For the list:\n";
                    list.print();
                    cout << "For the vector:\n";
                    vec.print();
                    cout << "\n\n";
                }

                sorter_for_list.cocktail_sort(list, 0, list.getLength() - 1);
                sorter_for_vector.cocktail_sort(vec, 0, list.getLength() - 1);
                if (var == 1)
                {
                    cout << "For the list:\n";
                    list.print();
                    cout << "For the vector:\n";
                    vec.print();
                    cout <<"\n\n";
                }
                list.isSorted();
                vec.isSorted();

                break;
            }
            case 3:
            {
                cout << "Input the length of the array: \n";
                cin >> n;
                main_array = ArrayGenerator(n).GenerateRandomArray();

                Linked_List_Sequence<int> list(main_array, static_cast<int>(main_array.size()));
                vectorSequence<int> vec(main_array);

                cout << "Do you want to compare arrays before the sorting ans after? (1-yes, 2-no)\n";
                int var;
                cin >> var;
                if (var == 1)
                {
                    cout << "For the list:\n";
                    list.print();
                    cout << "For the vector:\n";
                    vec.print();
                    cout << "\n\n";
                }

                sorter_for_list.insertion_sort(list, 0, list.getLength() - 1);
                sorter_for_vector.insertion_sort(vec, 0, list.getLength() - 1);
                if (var == 1)
                {
                    cout << "For the list:\n";
                    list.print();
                    cout << "For the vector:\n";
                    vec.print();
                    cout <<"\n\n";
                }
                list.isSorted();
                vec.isSorted();

                break;
            }
            case 4:
            {
                cout << "Input the length of the array: \n";
                cin >> n;
                main_array = ArrayGenerator(n).GenerateRandomArray();

                Linked_List_Sequence<int> list(main_array, static_cast<int>(main_array.size()));
                vectorSequence<int> vec(main_array);

                cout << "Do you want to compare arrays before the sorting ans after? (1-yes, 2-no)\n";
                int var;
                cin >> var;
                if (var == 1)
                {
                    cout << "For the list:\n";
                    list.print();
                    cout << "For the vector:\n";
                    vec.print();
                    cout << "\n\n";
                }

                sorter_for_list.count_sort(list, 0, list.getLength() - 1);
//                sorter_for_vector.count_sort(vec, 0, list.getLength() - 1);
                if (var == 1)
                {
                    cout << "For the list:\n";
                    list.print();
                    cout << "For the vector:\n";
                    vec.print();
                    cout <<"\n\n";
                }
                list.isSorted();
                vec.isSorted();

                break;
            }
            case 5:
            {
                cout << "Input the length of the array: \n";
                cin >> n;
                main_array = ArrayGenerator(n).GenerateRandomArray();

                Linked_List_Sequence<int> list(main_array, static_cast<int>(main_array.size()));
                vectorSequence<int> vec(main_array);

                cout << "Do you want to compare arrays before the sorting ans after? (1-yes, 2-no)\n";
                int var;
                cin >> var;
                if (var == 1)
                {
                    cout << "For the list:\n";
                    list.print();
                    cout << "For the vector:\n";
                    vec.print();
                    cout << "\n\n";
                }

                sorter_for_list.quick_sort(list, 0, list.getLength() - 1);
                sorter_for_vector.quick_sort(vec, 0, list.getLength() - 1);
                if (var == 1)
                {
                    cout << "For the list:\n";
                    list.print();
                    cout << "For the vector:\n";
                    vec.print();
                    cout <<"\n\n";
                }
                list.isSorted();
                vec.isSorted();

                break;
            }
//            case 8:
//                cout << "What array's length do you test?\n";
//                cin >> n;
//                main_array.resize(n);
//                cout << "What type of array do you want to test?\n1. Random array\n2. Sorted array\n";
//                cin >> type_of_array;
//                switch (type_of_array)
//                {
//                    case 1:
//                        main_array = ArrayGenerator(n).GenerateRandomArray();
//                        break;
//                    case 2:
//                        main_array = ArrayGenerator(n).GenerateSortedArray();
//                        break;
//                }
////                Bench(main_array, n);
//                TestSortFunc("Bubble", bubble_sort, main_array, 0, n - 1);
//                TestSortFunc("Cocktail", cocktail_sort, main_array, 0, n - 1);
//                TestSortFunc("Insertion", insertion_sort, main_array, 0, n - 1);
//                TestSortFunc("Count", count_sort, main_array, 0, n - 1);
//                TestSortFunc("Quick", quick_sort, main_array, 0, n - 1);
//                break;
            case 0:
                break;
            default:
                cout << "Wrong choice!\n";
                break;
        }
    }
}
