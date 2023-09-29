#include <iostream>
using namespace std;

/**
 * @brief Сортировка пузырьком
 * @param arr массив
 * @param size размер массива
 */
void bubbleSort(int* arr,const size_t size);

/**
 * @brief Создание массива рандомно
 * @param size размер массива
 * @return массив
 */
int* CreateArray(const size_t size);


/**
 * @brief ввод и проверка на корректное число элементов массива
 * @param message вывод определённой фразы при выполнении
 * @param size размер массива
 */
size_t GetSize(const std::string& message);

/**
 * @brief Вывод массива на консоль.
 * @param array массив.
 * @param size_ размер массива.
 */
void Print(int* arr,const size_t size);

int main() 
{
  size_t size;
  
  try{
    size = GetSize("введите размер массива ");
  }
  catch (const std::invalid_argument& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
        return 1;
  }
  size_t SizeArr = size;
  int* myArray = nullptr;

  
  myArray = CreateArray(SizeArr);
  
  cout << "Массив: ";
  Print(myArray,SizeArr);
  cout << "\n Массив в отсортированном виде методом пузырька" << endl;
  bubbleSort(myArray, size);
  
  Print(myArray,SizeArr);
  if (myArray != nullptr)
{
   delete[] myArray;
   myArray = nullptr;
}


  return 0;
  
}

size_t GetSize(const std::string& message){
    int size = -1;
    std::cout << message;
    std::cin >> size;

    if (size <= 0)
    {
        throw std::out_of_range("Incorrect size. Value has to be greater or equal zero.");
    }

    return size;
}

int* CreateArray(const size_t size) {
    
    int* array = new int[size];
    srand(time(0));
    for (int i=0; i<size; i++){
        array[i]=rand() % 100;
    }
    return array;
}

void bubbleSort(int* arr,const size_t size)
{
    size_t i, j;
    for (i = 0; i < size - 1; i++)
        for (j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1])
            {
               swap(arr[j], arr[j + 1]);

            }
}

void Print(int* arr,const size_t size){
  for(size_t i =0 ; i<size; i++){
    cout<< " " << arr[i] << " ";
  }
}