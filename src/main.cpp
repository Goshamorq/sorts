#include <sorts.h>

int main()
{
    const string MENU = "1. Enter the array by keyboard\n2. Enter the array by random\n3. Bubble sort\n4. Cocktail "
                        "sort\n5. Insertion sort\n6. Count sort\n7. Quick sort\n8. Test\n0. Exit\n";
    int choice = -1;
    int n = -1;

    vector<int> main_array; // массив с числами

    while (choice != 0)
    {
        cout << MENU;
        cin >> choice;
        switch (choice)
        {
            case 1:
                cout << "Choose a length of the array\n";
                while (n < 0)
                    cin >> n;
                cout << "Enter an elements\n";
                main_array.resize(n);
                for (int i = 0; i < n; ++i)
                    cin >> main_array[i];
                break;

            case 2:
                cout << "Choose a length of the array\n";
                while (n < 0)
                    cin >> n;
                main_array.resize(n);
                for (int i = 0; i < n; ++i)
                    main_array[i] = rand() % INT32_MAX;
                break;
            case 3:
                if (main_array.empty())
                {
                    cout << "Enter the array!\n";
                    break;
                }
                TestSortFunc("Bubble sort", bubble_sort,  main_array, 0, n - 1);
                break;
            case 4:
                if (main_array.empty())
                {
                    cout << "Enter the array!\n";
                    break;
                }
                TestSortFunc("Cocktail sort", cocktail_sort,  main_array, 0, n - 1);
                break;
            case 5:
                if (main_array.empty())
                {
                    cout << "Enter the array!\n";
                    break;
                }
                TestSortFunc("Insertion sort", insertion_sort,  main_array, 0, n - 1);
                break;

            case 6:
                if (main_array.empty())
                {
                    cout << "Enter the array!\n";
                    break;
                }
                TestSortFunc("Count sort", count_sort,  main_array, 0, n - 1);
                break;

            case 7:
                if (main_array.empty())
                {
                    cout << "Enter the array!\n";
                    break;
                }
                TestSortFunc("Quick sort", quick_sort,  main_array, 0, n - 1);
                break;
            case 8:
                cout << "What array's length do you test?\n";
                cin >> n;
                main_array.resize(n);
                for (int i = 0; i < n; ++i)
                    main_array[i] = rand() % INT32_MAX;
//                TestSortFunc("Bubble", bubble_sort, main_array, 0, n - 1);
//                TestSortFunc("Cocktail", cocktail_sort, main_array, 0, n - 1);
                TestSortFunc("Insertion", insertion_sort, main_array, 0, n - 1);
                TestSortFunc("Count", count_sort, main_array, 0, n - 1);
                TestSortFunc("Quick", quick_sort, main_array, 0, n - 1);
                break;
            case 0:
                break;


        }
    }

}
