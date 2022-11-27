Declear: 
bitset< number > bt;


Set all bits to 1: 
bt.set();


Find the first position with 1 set:
bt._Find_first(); (N/32 complexity);
if no 1 is found, it returns the size of the bitset


Find the first position with 1 set which is > an index:
bt._Find_next(idx);
if no 1 is found, it returns the size of the bitset


Flip all the bits: 
bt.flip();

The number of set bits in the bitset: 
bt.count();

Geeks for geeks functions:

 // test function return 1 if bit is set else returns 0
    for (int i = 0; i < set8.size(); i++)
        cout << set8.test(i) << " ";

  
    // any function returns true, if atleast 1 bit is set
    if (!set8.any())
        cout << "set8 has no bit set.\n";
  
    if (!bset1.any())
        cout << "bset1 has no bit set.\n";
  

    // none function returns true, if none of the bit is set
   
    if (!bset1.none())
        cout << "bset1 has some bit set\n";
  

    // bset.set() sets all bits to 1
    cout << set8.set() << endl;
  

    // bset.set(pos, b) makes bset[pos] = b
    cout << set8.set(4, 0) << endl;
  

    // bset.set(pos) makes bset[pos] = 1  i.e. default is 1
    cout << set8.set(4) << endl;
  

    // reset function makes all bits 0
    cout << set8.reset(2) << endl; (make only bit 2 to 0)
    cout << set8.reset() << endl;
  

    // flip function flips all bits i.e.  1 <-> 0 and  0 <-> 1
    cout << set8.flip(2) << endl; (flip only bit 2)
    cout << set8.flip() << endl;
  

    // Converting decimal number to binary by using bitset
    int num = 100;
    cout << "\nDecimal number: " << num
         << "  Binary equivalent: " << bitset<8>(num);
