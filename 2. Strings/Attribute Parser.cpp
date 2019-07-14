/**input:

4 3
<tag1 value = "HelloWorld">
<tag2 name = "Name1">
</tag2>
</tag1>
tag1.tag2~name
tag1~name
tag1~value

output:
Name1
Not Found!
HelloWorld

*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

#define ok cout<<"ok"<<endl


int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    vector <string> a,qs,tags;
    map <string, string> mp;
    map<string,int>tt;
    int n,q,i;
    cin>>n>>q;
    getchar();
    for(i=0; i<n; i++)
    {
        string s;
        getline(cin, s);
        a.push_back(s);
        //cout<<s<<endl;
        //cout<<a[i].front()<<endl;
    }
    int t;
    t = 0;
    for(i=0; i<n; i++)
    {
        int j;
        char x = '1';

        //cout<<a[i].size()<<endl;
        for(j=0; j<a[i].size()-2; j++)
        {
            //cout<<i <<" "<<j<<endl;
            string tag;
            tag = "";
            if(a[i][j]=='<' && a[i][j+1]=='/' )
            {
                j+=2;
                while(a[i][j]!='>')
                {
                    tag+=a[i][j];
                    j++;
                }
                //cout<<tag<<endl;
                tt[tag]=-1;
                if(!a[i][j+1])
                {
                    break;
                }
            }
            // ok;
           if( a[i][j] == '<' && a[i][j+1] != '/')
            {
                j++;
                while(a[i][j]!=' ' && a[i][j]!='>')
                {
                    tag += a[i][j];
                    j++;
                }
                // ok;
                tags.push_back(tag);
                tt[tag]++;
                //cout<<"tag = "<<tag<<endl;
                t++;
                tag+='~';
                string y;
                y=tag;
                //out<<" ?= ";
                //cout<<a[i][j]<<endl;
                if(a[i][j]==' ')
                {
                     j++;
                }
                while(a[i][j]!='>')
                {
                    tag = y;
                    while(a[i][j]!=' ')
                    {
                        tag+=a[i][j];
                        //cout<<tag;
                        j++;
                    }
                    // cout<<endl;
                    //ok;
                   // cout<<"tag = "<<tag<<" " ;
                    do
                    {
                        j++;
                    }
                    while(a[i][j]!='"');
                    //ok;
                    //cout<<"A = "<<a[i][j]<<endl;
                    j++;
                    string value;
                    value ="";
                    while(a[i][j]!='"')
                    {
                        value += a[i][j];
                        j++;
                    }
                    //ok;
                    //cout<<"value = "<<value<<endl;
                   // mp[tag]=value;
                    //cout<<"mp ["<<tag<<"] = "<<value<<endl;
                    string h;
                    h = "";
                    int z = 0;

                    if(t>0)
                    {
                        z = t;
                        while(z>1)
                        {
                            if(tt[tags[t-z]] > 0)
                            {
                                h += tags[t-z];
                                h+=".";

                            }
                            z--;
                            //cout<<"lol";
                        }
                        h+=tag;
                        tag = h;
                    }
                    //ok;
                    //cout<<"tag = "<<tag<<endl<<"val = "<<value<<endl;
                    if(!mp[tag].size()){
                        mp[tag]=value;
                        //cout<<"mp ["<<tag<<"] = "<<value<<endl;
                    }
                    j++;
                    if(a[i][j]==' ')
                        j++;
                }
            }
        }
    }
    //getchar();
    //cout<<"vame"<<endl;

    for(i=0; i<q; i++)
    {
        string s;
        getline(cin, s);
        //cout<<s<<endl;
        if(mp[s].size()>0)
        {
            cout<<mp[s]<<endl;
        }
        else
        {
            cout<<"Not Found!"<<endl;
        }
    }

    return 0;
}

/**
10 10
<a value = "GoodVal">
<b value = "BadVal" size = "10">
</b>
<c height = "auto">
<d size = "3">
<e strength = "2">
</e>
</d>
</c>
</a>
a~value
b~value
a.b~size
a.b~value
a.b.c~height
a.c~height
a.d.e~strength
a.c.d.e~strength
d~sze
a.c.d~size
*/

/**
GoodVal
Not Found!
10
BadVal
Not Found!
auto
Not Found!
2
Not Found!
3
*/

/**
16 14
<tag1 v1 = "123" v2 = "43.4" v3 = "hello">
</tag1>
<tag2 v4 = "v2" name = "Tag2">
<tag3 v1 = "Hello" v2 = "World!">
</tag3>
<tag4 v1 = "Hello" v2 = "Universe!">
</tag4>
</tag2>
<tag5>
<tag7 new_val = "New">
</tag7>
</tag5>
<tag6>
<tag8 intval = "34" floatval = "9.845">
</tag8>
</tag6>
tag1~v1
tag1~v2
tag1~v3
tag4~v2
tag2.tag4~v1
tag2.tag4~v2
tag2.tag3~v2
tag5.tag7~new_val
tag5~new_val
tag7~new_val
tag6.tag8~intval
tag6.tag8~floatval
tag6.tag8~val
tag8~intval
*/

/**
123
43.4
hello
Not Found!
Hello
Universe!
World!
New
Not Found!
Not Found!
34
9.845
Not Found!
Not Found!
*/
