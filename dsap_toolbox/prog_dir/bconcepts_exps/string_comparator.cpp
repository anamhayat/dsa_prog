#include <iostream>
using namespace std;

// idea at the end, T.C  =O(min(m, n)), S.C = o(1). Big Oh
// insights gained, the string type is very flexible in C++ too, except for splicing

void custom_strcmp(string &x, string &y)
{
    int flag = 0;
    // logic starts here
    // trav is the number of iterations
    int trav = x.size() < y.size() ? x.size() : y.size();

    //length matters only if (smaller string is
    //same as initial part of the bigger string
    //part from 0 to len(small) - 1
    //if (we get zero by general traversal,
    //the bigger string is down in the lex
    int i = 0; // i for index

    while (i < trav)
    {
        // cout << xi << " being compared with " << yi << endl; // for debugging A
        char xi = x[i] & '_', yi = y[i] & '_'; // both uppercased now
        if (xi != yi)
        {
            if (xi > yi)
                flag = 1;
            else
                flag = -1;
            // cout << "Stopped...\n"; // debugging b
            break;
        }
        i++;
    }
    //loop will break if we reach a value where they are not equal
    //logic ends, we get the flag value

    // if length is same then flag value is final
    // if not then we need to check if strings are same for the length if the smaller string
    if (flag == 0)
    {
        if (x.size() != y.size())
            flag = x.size() > y.size() ? 1 : -1;
    }

    // only for front end
    string state = "";

    if (flag == 0)
        state = "is the same as";
    else
        state = flag == 1 ? "comes after" : "comes before";
    cout << x << " " << state << " " << y << "\n";
    // Time taken is min(m, n)
}

int main()
{
    cout << "String Comparator(case In-sensitive)\n"; // Heading

    string x = "", y = ""; // Taking the strings as input
    cout << "String 1: ";
    getline(cin, x);
    std::cout << "String 2: ";
    getline(cin, y);

    // printing the verdict
    custom_strcmp(x, y);
    return 0; //end
}

/*
        ------------------<< IDEA >>--------------------
def strcmp(x, y))
	flag = 0
	trav = 1
	// logis starts here
	// trav is the number of iterations

if (x.size()<y.size())
	trav = x.size()
// length matters only if (smaller string is
// same as initial part of the bigger string
// part from 0 to len(small) - 1
// if (we get zero by general traversal,
//the bigger string is down in the lex
else)
	trav = y.size()
i= 0 // i for index
	while index<trav and flag == 0)
		if (x[i] == y[i])
			continue
	 // no else coz continue does it
	 flag = 1 if (x[i]>y[i] else -1
	 // loop will break if (we reach a value
	 //where they are not equal
	 // logic ends, we get the flag value
if (flag==0)
	if (x.size() == y.size())
		return "Equal"
if (flag == 1)
	return "2 comes first"
return "1 comes first"
print("String Comparator")
x = input("String 1) ")
y = input("String 2) ")
print("The strings are ", strcmp(x, y))
*/
