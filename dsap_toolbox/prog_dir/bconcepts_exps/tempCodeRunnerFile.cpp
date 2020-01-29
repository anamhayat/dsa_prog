int main()
{
    cout << "String Comparator(case In-sensitive)\n"; // Heading


    string x = "", y = ""; // Taking the strings as input
    cout << "String 1: ";
    getline(cin, x);
    cout << "String 2: ";
    getline(cin, y);


    cout << custom_strcmp(x, y) + "\n"; // printing the verdict

    return 0; //end
}