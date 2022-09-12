/*
    int num{0xAA};
    cout << oct << num << endl;  // 170
    cout << dec << num << endl;  // 250
    cout << hex << num << endl;  // aa
    cout << uppercase << hex << num << endl;
    cout << nouppercase << hex << num << endl;
    cout << showbase << endl;
    cout << oct << num << endl;  // 170
    cout << dec << num << endl;  // 0250
    cout << hex << num << endl;  // 0xAA
    cout << uppercase << hex << num << endl;
    cout << nouppercase << hex << num << endl;

    double fl1{+3.14000000};
    cout << showpoint << endl;
    cout << showpos << endl;
    cout << fl1 << endl;                // +3.14000
    cout << fixed << fl1 << endl;       // +3.140000
    cout << scientific << fl1 << endl;  // +3.140000e+000

    cout << noshowpoint << endl;
    cout << noshowpos << endl;
    cout << fl1 << endl;                // 3.140000e+000
    cout << fixed << fl1 << endl;       // 3.140000
    cout << scientific << fl1 << endl;  // 3.140000e+000


    bool bool1{0};
    cout << boolalpha << bool1 << " " << noboolalpha << bool1 << endl;  // false 0

    cout << "W" << endl;
    cout << "     W" << endl;
    cout << setw(5) << setfill('-') << "  W" << endl;           // "--  W"
    cout << setw(6) << setfill('-') << "  W" << endl;           // "---  W"
    cout << setw(10) << right << setfill('-') << "W" << endl;   // "---------W"
    cout << setw(10) << left  << setfill('-') << "W" << endl;   // "W---------"
    cout << setw(10) << right << setfill('-') << " W" << endl;   // "-------- W"
    cout << setw(10) << left  << setfill('-') << "W " << endl;   // "W --------"

  int n = -77;
    cout << dec << setfill('_');
    cout.width(6); cout <<  internal << n << '\n';  // "-___77"
    cout.width(6); cout <<  left << n << '\n';      // "-77___"
    cout.width(6); cout <<  right << n << '\n';     // "___-77"

//--Constantes-------------------------------------------------------------------
    constexpr int DATA = 120;

    auto someData = 2147483647;         // deduction de type automatique
    decltype (someData) other{0};
    // or
    //decltype (4294967294) other{0};
    cout << sizeof (other) << endl;
    other = 4294967294;
    cout << other << endl;

//-- sufix --
    // u,U unsigned
    // l,L long int
    // ll,LL long long int
    // f,F float

    int   int0 = 120u;
    float fl2 = 14.0f;
    fl2 = float (int0);
// -- limits --
    cout << "suffix :" << numeric_limits<short int>::max() << endl;
    cout << "suffix :" << numeric_limits<short int>::min() << endl;
    cout << "suffix :" << numeric_limits<short int>::is_signed<< endl;
    cout << "suffix :" << numeric_limits<short int>::is_const<< endl;


    string chaine{"1"};
    string nom,prenom;
    string& nomr=nom ;

    getline (cin,chaine);   // "   lksjdlksj lkjfsldf lsdkj  <cr>"
    cin >> nom >> prenom ;  // "Samuel Aubert<cr>"
    cin.ignore(256,'a');
    cout << "Nom:" << nomr << " Prenom:" << prenom << endl;
    cout << chaine;
*/
