#pragma once

template<class T>
class BinaryHeap
{
private:
    T* mas;
    int capacity;
private:
    void Swap(T* data1, T* data2)
    {
        T help = *data1;
        *data1 = *data2;
        *data2 = help;
    }
public:
    int size;
    BinaryHeap()
    {
        size = 0;
        capacity = 4;
        mas = new T[capacity];
    }
    BinaryHeap(int capacity)
    {
        size = 0;
        this->capacity = capacity;
        mas = new T[capacity];
    }

    void Show(int j, int m)
    {
        for (int i = j; i < m; i++)
        {
            cout << mas[i] << " ";
        }
    }

    T Get()
    {
        T res = mas[0];
        Delete();
        return res;
    }

    void Add(T data)
    {
        if (size == capacity)
        {
            capacity *= 2;
            T* newmas = new T[capacity];
            for (int i = 0; i < size; i++)
            {
                newmas[i] = mas[i];
            }
            delete mas;
            mas = newmas;
        }
        mas[size] = data;
        int point = size;
        int prev = (size - 1) / 2;
        while (mas[point] < mas[prev])
        {
            Swap(&mas[point], &mas[prev]);
            point = prev;
            prev = (point - 1) / 2;
        }
        size++;
    }

    void Delete()
    {
        mas[0] = mas[size - 1];

        int point = 0;
        int left = 1;
        int right = 2;
        while (true)
        {
            if (right < size - 1)
            {
                int min = mas[point] < mas[left] ? (mas[point] < mas[right] ? point : right) : (mas[left] < mas[right] ? left : right);
                if (point == min)
                {
                    break;
                }
                else
                {
                    Swap(&mas[point], &mas[min]);
                    point = min;
                    left = point * 2 + 1;
                    right = left + 1;
                }
            }
            else if (left == size - 1)
            {
                if (mas[point] < mas[left])
                {
                    Swap(&mas[point], &mas[left]);
                }
                break;
            }
            else
            {
                break;
            }

        }
        size--;
        if (size == capacity / 2)
        {
            capacity = size;
            T* newmas = new T[capacity];
            for (int i = 0; i < size; i++)
            {
                newmas[i] = mas[i];
            }
            delete mas;
            mas = newmas;
        }
    }
};