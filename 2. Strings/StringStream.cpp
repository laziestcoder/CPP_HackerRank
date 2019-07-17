#include <sstream>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

vector<int> parseInts(string str)
{
    // Complete this function
    vector<int> sb;
    int i,k=0;
    string s="",ss[100000];
    //cout<<str.size()<<endl;
    for(i=0; i<str.size(); i++)
    {
        if(str[i+1]==',' || i+1==str.size())
        {
            s+=str[i];
            //cout<<s<<endl;
            ss[k] = s;
            s="";
            k++;
            i++;
        }
        else
        {
            s+=str[i];
        }

    }

    int m=0,y=0,p=0,sign = 0;
    //cout<<sizeof(ss)/800<<endl;
    //cout<<k<<endl;
    for(i=0; i<k; i++)
    {
        m=0;
        y=0;
        sign = 0;
        for(p=ss[i].size()-1; p>=0; p--)
        {
            if(ss[i][p]=='-')
            {
                sign = 1;
            }else{
            m+=(ss[i][p]-'0'+0)*pow(10,y);
            }
            y++;
        }
        sign == 1 ?  m *=-1 : m *= 1;
        sb.push_back(m);
    }
    return sb;
}

int main()
{
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++)
    {
        cout << integers[i] << "\n";
    }

    return 0;
}

/**

-847,728,-239,371,-348,541,-130,-367,-165,-19,-38,-452,917,339,-989,-645,-238,538,-989,-228,-190,-364,557,-491,-832,830,-623,-348,366,413,-650,-499,-388,-847,-557,-211,-600,74,-326,505,789,-98,-747,966,559,-631,949,-300,739,927,723,-405,359,-787,-321,-289,-630,-883,-567,-199,271,745,-341,-374,-141,157,952,372,903,-346,678,-689,752,-86,-376,45,820,406,378,38,457,300,824,218,364,357,-302,359,-314,858,-408,-315,159,-140,-744,-654,575,459,-898,-197,940,-253,-154,603,-704,505,-653,379,-94,74,-539,474,-27,-529,875,-184,-39,635,-986,-898,-22,-707,422,84,-368,518,242,213,945,-639,945,-886,36,794,734,523,-231,386,-72,621,944,914,-433,-220,7,-96,470,359,-762,-101,-607,451,-749
*/

/**output
-847
728
-239
371
-348
541
-130
-367
-165
-19
-38
-452
917
339
-989
-645
-238
538
-989
-228
-190
-364
557
-491
-832
830
-623
-348
366
413
-650
-499
-388
-847
-557
-211
-600
74
-326
505
789
-98
-747
966
559
-631
949
-300
739
927
723
-405
359
-787
-321
-289
-630
-883
-567
-199
271
745
-341
-374
-141
157
952
372
903
-346
678
-689
752
-86
-376
45
820
406
378
38
457
300
824
218
364
357
-302
359
-314
858
-408
-315
159
-140
-744
-654
575
459
-898
-197
940
-253
-154
603
-704
505
-653
379
-94
74
-539
474
-27
-529
875
-184
-39
635
-986
-898
-22
-707
422
84
-368
518
242
213
945
-639
945
-886
36
794
734
523
-231
386
-72
621
944
914
-433
-220
7
-96
470
359
-762
-101
-607
451
-749
*/

/**
Other Solutions

#include <bits/stdc++.h>
using namespace std;

vector<int> parseInts(string str) {
    stringstream ss(str);
    vector<int> result;
    char ch;
    int tmp;
    while(ss >> tmp) {
        result.push_back(tmp);
        ss >> ch;
    }
    return result;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++)
        cout << integers[i] << "\n";
    return 0;
}

-------------------

#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
    stringstream ss;
    ss << str;

    int i;
    vector<int> is;

    while(ss >> i) {
        is.push_back(i);

        if (ss.peek() == ',')
            ss.ignore();
    }

    return is;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }

    return 0;
}

----------------

#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
    vector<int> res;
    bool read;
    stringstream ss(str);
    char ch;
    int i = 0, nextInt;

    while (1){
        if (i%2==0){
            read = (ss >> nextInt);
            if (!read) break;
            res.push_back(nextInt);
        }
        else{
            read = (ss >> ch);
        }
        i++;
    }
   return res;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }

    return 0;
}
*/
