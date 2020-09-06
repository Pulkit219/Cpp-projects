#include "Dog.h"
using namespace std;







/**
================================================================================================
TASK 4
================================================================================================
 */

//struct is_alphabetic {
//    bool operator()(char c) { return !std::isalpha(c); }
//};
bool is_alphabetic(char c) { return !std::isalpha(c);}  //it will return true for spaces(non-alpha) and then remove_copy_if will remove those returned true
bool is_palindrome(const string& phrase)
{
    std::string temp;
    //std::remove_copy_if to move only alphabet characters from phrase to temp, storing into temp thus forcing the need for back_insertor
    std::remove_copy_if(phrase.begin(), phrase.end(), back_inserter(temp), is_alphabetic);
    //std::transform to convert all characters in temp to lowercase
    std::transform(temp.begin(), temp.end(), temp.begin(),[](unsigned char c){ return std::tolower(c); });
  /*using std::equal to compare the first half of temp with its second half, moving forward in
first half starting at temp.begin() and moving backward in the second half starting
at temp.rbegin(). Set result to the value returned by the call to std::equal;*/
    return std::equal(temp.begin(), temp.begin() + temp.size() / 2, temp.rbegin());

}

// test_is_palindrome is a function already given in the assignment.
void test_is_palindrome()
{
    std::string str_i = std::string("Was it a car or a cat I saw?");
    std::string str_u = std::string("Was it a car or a cat U saw?");
    std::cout << "the phrase \"" + str_i + "\" is " +
        (is_palindrome(str_i) ? "" : "not ") + "a palindrome \n";
    std::cout << "the phrase \"" + str_u + "\" is " +
        (is_palindrome(str_u) ? "" : "not ") + "a palindrome \n";
}

/*
================================================================================================
TASK 4  END
================================================================================================
 */







 /*
 ================================================================================================
 TASK 5
 ================================================================================================
  */
template <class Iterator > // template header
std::pair < Iterator, bool > // function template return type
second_max(Iterator start, Iterator finish) // function signature
{
    bool flag = false;
    Iterator nextElement = start;
    Iterator temp = start;

   
    while (true && start != finish )    //loop until it reaches end
    {
        if ((*start == *nextElement) && flag == false) {
            flag = false;
            temp = start;
        }
        if (*start < *nextElement) {
            flag = true;
            temp = start;
            start = nextElement;
        }
        ++nextElement;                 //if increment of next = end()/finish then there was only 1 element in vector
        if (nextElement == finish)
        {
            ++start;
            nextElement = start;
        }
        if (start == finish) break; //break out of while loop 
    }
    return make_pair(temp, flag);
}

  // test_second_max is a function already given in the assignment.
void test_second_max(std::vector<int> vec)
{
    // note: auto in the following statement is deduced as
    // std::pair<std::vector<int>::iterator, bool>
    auto retval = second_max(vec.begin(), vec.end());
    if (retval.second)
    {
        cout << "The second largest element in vec is "
            << *retval.first << endl;
    }
    else
    {
        if (retval.first == vec.end())
            cout << "List empty, no elements\n";
        else
            cout << "Container's elements are all equal to "
            << *retval.first << endl;
    }
}
  /*
================================================================================================
  TASK 5 END
================================================================================================
   */







/*
================================================================================================
TASK 6
================================================================================================
*/
//PART A
int testCountStringsLambda(std::vector<std::string>& vec, int n)
{
    //simply returning string count that are of length provided by user
    int Lambda = std::count_if(vec.begin(), vec.end(), [&n](const string& str) {return (n == str.length()); });
    return Lambda;
}


//PART B
bool FreeFun(string str, int n) { return (str.length() == n); }
int testCountStringsFreeFun(std::vector<std::string>& vec, int n)
{
    int count = std::count_if(vec.begin(), vec.end(), std::bind(FreeFun, std::placeholders::_1, n));   //turned into unary
    return count;
}


//PART C
struct Functor {           // Functor
    Functor(int n) : number(n) {}
    bool operator() (const string& str) { return (str.length() == number); }
private:
    int number;
};

int testCountStringsFunctor(std::vector<std::string> vec, int n)
{
    int count = std::count_if(vec.begin(), vec.end(), Functor(n));
    return count;
}
/*
================================================================================================
TASK 6 END
================================================================================================
*/








/*
================================================================================================
TASK 7
================================================================================================
*/

struct compare {
    bool operator()(const string& lhs,const string& rhs) const {

        const size_t lhsLen = lhs.length();
        const size_t rhsLen = rhs.length();

        if (lhsLen == rhsLen)
        {
            return (lhs < rhs); // when two strings have the same length switch to default comparision
                                     
        }

        return (lhsLen < rhsLen); // othwerwise compares with the length
    }
};


// multisetUsingMyComparator is a function already given in the assignment.
void multisetUsingMyComparator()
{
    std::multiset<std::string, compare> strSet; // an empty set initialized with customized comparator

    // a set that uses the default std::less<int> to sort the set elements
    std::vector<std::string> vec{ "C", "BB", "A", "CC", "A", "B",
                                  "BB", "A", "D", "CC", "DDD", "AAA" };

    // copy the vector elements to our set. 
    // We  must use a general (as oppsed to a front or back) inserter.
    // (set does not have push_front or push_back members,
    // so we can't use a front or back inserter)

    std::copy(vec.begin(), vec.end(),                // source start and finish
        std::inserter(strSet, strSet.begin())); // destination start with
                                                // a general inserter

// create an ostream_iterator for writing to cout, 
// using a space " " as a separator
    std::ostream_iterator<std::string> out(cout, " ");

    // output the set elements to cout separating them with a space
    std::copy(strSet.begin(), strSet.end(), out);
}
/*
================================================================================================
TASK 7 END
================================================================================================
*/







int main()
{
    /*
================================================================================================
TASK 3.1
 */
    DogMapDefault dogMap;
    load_csvFile_Normal_Loop(dogMap, "dogDB.csv");
    cout << dogMap << endl;


    /*
================================================================================================
TASK 3.2
 */
    DogMapDefault dogMap2;
    load_csvFile_For_Each(dogMap2, "dogDB.csv");
    cout << dogMap2 << endl;


    /*
================================================================================================
TASK 3.3
 */
    DogMapDefault dogMap3;
    load_csvFile_Transform(dogMap3, "dogDB.csv");
    cout << dogMap3 << endl;

 /*
================================================================================================
TASK 3.4*/
    DogMapGreater dogMap4;
    load_csvFile_Normal_Loop(dogMap4, "dogDB.csv");
    cout << dogMap4 << endl;


    /*
================================================================================================
TASK 3.5
 */

    DogMapDefault dog_map5;
    load_csvFile_Normal_Loop(dog_map5, "dogDB2.csv");
    DogMapDefault breedRangeMap1 = findBreedRange(dog_map5, std::string("Greyhound"));
    cout << breedRangeMap1 << "----------" << endl;
    DogMapDefault breedRangeMap2 = findBreedRange(dog_map5, std::string("Lakeland Terrier"));
    cout << breedRangeMap2 << "----------" << endl;
    DogMapDefault breedRangeMap3 = findBreedRange(dog_map5, std::string("Pug"));
    cout << breedRangeMap3 << "----------" << endl;
    DogMapDefault breedRangeMap4 = findBreedRange(dog_map5, std::string("Xyz"));
    cout << breedRangeMap4 << "----------" << endl;


    /*
================================================================================================
TASK 4
 */
    test_is_palindrome();
    cout << "\n";


    /*
================================================================================================
TASK 5
 */
    std::vector<int> v1{ 1 }; // one element
    test_second_max(v1);
    std::vector<int> v2{ 1, 1 }; // all elements equal
    test_second_max(v2);
    std::vector<int> v3{ 1, 1, 3, 3, 7, 7 }; // at least with two distict elements
    test_second_max(v3);
    std::vector<int> v4;    //empty vector
    test_second_max(v4);
    cout << "\n";


    /*
================================================================================================
TASK 6
 */
    std::vector<std::string> vecstr
    { "count_if", "Returns", "the", "number", "of", "elements", "in", "the",
    "range", "[first", "last)", "for", "which", "pred", "is", "true."
    };
    cout << testCountStringsLambda(vecstr, 5) << endl;
    cout << testCountStringsFreeFun(vecstr, 5) << endl;
    cout << testCountStringsFunctor(vecstr, 5) << endl;
    cout << "\n";


    /*
================================================================================================
TASK 7
 */
    multisetUsingMyComparator();
    cout << "\n";
    return 0;
}
