#include <iostream>
#include <vector>

using std::vector;
using std::cout;

// Jack puts doubles into an array and
// returns the number of elements in *count
double* get_from_jack(int* count)
{
    // Assume Jack's data is already available or fetched from somewhere
    // In this example, let's create a dummy array with some values

    const int jack_data_size = 5;
    double* jack_data = new double[jack_data_size];

    // Fill Jack's array with some values
    jack_data[0] = 20.3;
    jack_data[1] = 1.8;
    jack_data[2] = 46.5;
    jack_data[3] = 3.2;
    jack_data[4] = 0.9;
  

    // Set the count
    *count = jack_data_size;

    // Return the pointer to Jack's array
    cout << "Return address of first value of Jack's Data: " << jack_data << '\n';
    return jack_data;
    
}

vector<double>* get_from_jill()
{
    // Assume Jill's data is already available or fetched from somewhere
    // In this example, let's create a dummy vector with some values

    vector<double>* jill_data = new vector<double>;

    // Fill Jill's vector with some values
    jill_data->push_back(5.1);
    jill_data->push_back(3.7);
    jill_data->push_back(23.9);
    jill_data->push_back(4.2);
    jill_data->push_back(1.6);

    // Return the pointer to Jill's vector
    cout << "Return address of first value of Jill's Data: " << jill_data << '\n';
    return jill_data;
}


template<typename Iterator>
Iterator high(Iterator first, Iterator last)
// return an iterator to the element in [first:last) that has the highest value
{
    Iterator high = first;
    for (Iterator p = first; p != last; ++p)
        if (*high < *p) { high = p; }
                        cout << "This address and value will be returned from high() function call: " << high << ' ' << *high << '\n';  // print output to show what will be returned
    return high;
}



void fct()
{

    int jack_count = 0;
                        cout << "Jack count initial value: " << jack_count << '\n';     // print output to show variable state

    double* jack_data = get_from_jack(&jack_count);

                        cout <<"Jack count value now: " << jack_count << '\n';          // print output to show variable state change

    vector<double>* jill_data = get_from_jill();

    double* jack_high = high(jack_data, jack_data + jack_count);

    vector<double>& v = *jill_data;

    double* jill_high = high(&v[0], &v[0] + v.size());

    cout << "Jill's high " << *jill_high << "; Jack's high " << *jack_high;
    // . . .
    delete[] jack_data;
    delete jill_data;
}


int main()
{
    fct();
   
}