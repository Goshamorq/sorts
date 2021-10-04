#include "sorts.hpp"
#include "generators.hpp"
#include "sequence_list.hpp"
#include "ISorter.hpp"
#include "vectorSequence.hpp"
#include "test.hpp"
#include <functional>

int main()
{
    const string MENU = "1. Bubble sort\n2. Cocktail sort\n3. Insertion sort\n4. Count sort\n5. Quick sort\n0. "
                        "Exit\n";

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
                    cout << "\n\n";
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
                    cout << "\n\n";
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
                    cout << "\n\n";
                }
                list.isSorted();
                vec.isSorted();

                break;
            }
            case 4:
            {
                cout << "Input the length of the array: \n";
                cin >> n;
                main_array = ArrayGenerator(n).GenerateArrayForCount();

                Linked_List_Sequence<int> list(main_array, static_cast<int>(main_array.size()));
                vectorSequence<int> vec(main_array);

                cout << "Do you want to compare arrays before the sorting ans after? (0 - no, 1 - yes)\n";
                int var;
                cin >> var;
                if (var)
                {
                    cout << "For the list:\n";
                    list.print();
                    cout << "For the vector:\n";
                    vec.print();
                    cout << "\n\n";
                }

                sorter_for_list.count_sort(list, 0, list.getLength() - 1);
                sorter_for_vector.count_sort(vec, 0, list.getLength() - 1);

                if (var)
                {
                    cout << "For the list:\n";
                    list.print();
                    cout << "For the vector:\n";
                    vec.print();
                    cout << "\n\n";
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
                    cout << "\n\n";
                }
                list.isSorted();
                vec.isSorted();

                break;
            }
//            case 6:
//            {
//                n = 10000;
//                main_array = ArrayGenerator(n).GenerateReverseArray();
//                main_array = ArrayGenerator(n).GenerateRandomArray();
//                main_array = ArrayGenerator(n).GenerateArrayForCount();
//
//                auto bubble_vector = std::mem_fn(&ISorter<int, vectorSequence<int>>::bubble_sort);
//                auto cocktail_vector = std::mem_fn(&ISorter<int, vectorSequence<int>>::cocktail_sort);
//                auto insert_vector = std::mem_fn(&ISorter<int, vectorSequence<int>>::insertion_sort);
//                auto quick_list = std::mem_fn(&ISorter<int, Linked_List_Sequence<int>>::quick_sort);
//
//                BenchArray("bubble_array_reversed", sorter_for_vector, bubble_vector, main_array, n);
//                BenchArray("cocktail_array_reversed", sorter_for_vector, cocktail_vector, main_array, n);
//                BenchArray("insert_array_reversed", sorter_for_vector, insert_vector, main_array, n);
//                BenchList("quick_list_reversed", sorter_for_list, quick_list, main_array, n);
//
//
//
//                n = 1000;
//                main_array = ArrayGenerator(n).GenerateReverseArray();
//                auto bubble_list = std::mem_fn(&ISorter<int, Linked_List_Sequence<int>>::bubble_sort);
//                auto cocktail_list = std::mem_fn(&ISorter<int, Linked_List_Sequence<int>>::cocktail_sort);
//                auto insert_list = std::mem_fn(&ISorter<int, Linked_List_Sequence<int>>::insertion_sort);
//                BenchList("bubble_list_reversed", sorter_for_list, bubble_list, main_array, n);
//                BenchList("cocktail_list_reversed", sorter_for_list, cocktail_list, main_array, n);
//                BenchList("insert_list_reversed", sorter_for_list, insert_list, main_array, n);
//
//
//                n = 100000;
//                main_array = ArrayGenerator(n).GenerateReverseArray();
//                auto count_vector = std::mem_fn(&ISorter<int, vectorSequence<int>>::count_sort);
//                auto quick_vector = std::mem_fn(&ISorter<int, vectorSequence<int>>::quick_sort);
//                BenchArray("quick_array_reversed", sorter_for_vector, quick_vector, main_array, n);
//                BenchArray("count_array_reversed", sorter_for_vector, count_vector, main_array, n);
//

//                BenchArray("bubble_array_sorted", sorter_for_vector, bubble_vector, main_array, n);
//                BenchArray("cocktail_array_sorted", sorter_for_vector, cocktail_vector, main_array, n);
//                BenchArray("insert_array_sorted", sorter_for_vector, insert_vector, main_array, n);
//
//                BenchList("bubble_list_sorted", sorter_for_list, bubble_list, main_array, n);
//                BenchList("cocktail_list_sorted", sorter_for_list, cocktail_list, main_array, n);
//                BenchList("insert_list_sorted", sorter_for_list, insert_list, main_array, n);
//
//                BenchArray("quick_array_sorted", sorter_for_vector, quick_vector, main_array, n);
//                BenchArray("count_array_sorted", sorter_for_vector, count_vector, main_array, n);
//
//                BenchList("quick_list_sorted", sorter_for_list, quick_list, main_array, n);
//                BenchList("count_list_sorted", sorter_for_list, count_list, main_array, n);
//
//                break;
//            }
            case 0:
                break;
            default:
                cout << "Wrong choice!\n";
                break;
        }
    }
}