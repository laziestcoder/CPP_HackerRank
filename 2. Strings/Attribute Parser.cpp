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


/**
Others Solution
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

vector<string> tag_stack;
map<string, string> attrs;


void insert_attr(string & name, string & val) {
    string full;
    for(string & str : tag_stack)
        full += str + ".";
    full.pop_back();
    full += "~" + name;
    attrs[full] = val;

}

int main() {
    int n, q;
    cin >> n >> q;

    for(int i = 0; i < n; ++i) {
        char c; cin >> c;
        if(cin.peek() == '/') { // close
            string cn; cin >> cn;
            tag_stack.pop_back();
        }
        else { //open'
            string name;
            cin >> name;
            if(name.back() == '>') { //no attrs
                name.pop_back();
                tag_stack.push_back(name);
            }
            else {
                tag_stack.push_back(name);

                for(;;) {
                    string attr_name, attr_val, eq;
                    cin >> attr_name >> eq >> attr_val;
                    if(attr_val.back() == '>') { //last attr
                        attr_val.pop_back();
                        attr_val.pop_back();
                        attr_val = attr_val.substr(1);
                        insert_attr(attr_name, attr_val);
                        break;
                    }
                    else {
                        attr_val.pop_back();
                        attr_val = attr_val.substr(1);
                        insert_attr(attr_name, attr_val);
                    }
                }
            }

        }
    }

    for(int i = 0; i < q; ++i) {
        string quer;
        cin >> quer;
        if(attrs.find(quer) != attrs.end())
            cout << attrs[quer] << endl;
        else
            cout << "Not Found!" << endl;
    }


    return 0;
}

-----------------

#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <deque>
using namespace std;
typedef long long ll;
typedef pair<double, double> dd;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

int main(){
	int n, q; cin >> n >> q; string tmp;
	getline(cin, tmp);
	vector<string> h;
	map<string, string> m;
	for(int t=0;t<n;t++){
		string s; getline(cin, s);
		s += " $";
		if(s[1] == '/'){
			h.pop_back();
		}else{
			string val="";
			int i = 1;
			while(s[i] != ' ' && s[i] != '>'){
				val += s[i];
				i++;
			}
			h.push_back(val);

			string sofar = "";
			for(int i=0;i<h.size();i++){
				if(i != 0) sofar += ".";
				sofar += h[i];
			}

			while(true){
				val = ""; string arg = "";
				while(i < s.size() && s[i] == ' '){
					i++;
				}
				while(i < s.size() &&  s[i] != ' '){
					val += s[i];
					i++;
				}
				while(i < s.size() && s[i] != '\"'){
					i++;
				}
				i++;
				while(i < s.size() && s[i] != '\"'){
					arg += s[i];
					i++;
				}
				i++;i++;
				m[sofar+"~"+val] = arg;
				if(i >= s.size()-3) break;
			}

		}
	}
	for(int t=0;t<q;t++){
		string s; cin >> s;
		string def = "Not Found!";
		string ans = def;
		if(m.find(s) != m.end()){
			ans = m[s];
		}
		cout << ans << endl;
	}

}

---------
#include <cmath>
#include <cstdio>
#include <vector>
#include <list>
#include <unordered_map>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
std::unordered_map<std::string,std::unordered_map<std::string,std::string> > TagAttrVal;

 void Set(const std::string _name ,std::string &_attrName, const std::string &_attVal){
        auto val=_attVal;
        if(val[0]=='"'){
            val = val.substr(1,val.length()-1);
        }
        if(val[val.length()-1]=='"'){
            val = val.substr(0,val.length()-1);
        }
        TagAttrVal[_name][_attrName]=val;
}

// trim from start
static inline std::string &ltrim(std::string &s) {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
        return s;
}

// trim from end
static inline std::string &rtrim(std::string &s) {
        s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
        return s;
}

// trim from both ends
static inline std::string &trim(std::string &s) {
        return ltrim(rtrim(s));
}
inline void split(const std::string &s, std::vector<std::string> &_tokens,const char delimiter)
{
    size_t start = 0;
    size_t end = s.find_first_of(delimiter);

    while (end <= std::string::npos)
    {
        _tokens.emplace_back(s.substr(start, end - start));

        if (end == std::string::npos)
            break;

        start = end + 1;
        end = s.find_first_of(delimiter, start);
    }
}
std::string GetTagName(std::list<std::string> &_curretnTags){
    if(_curretnTags.empty())
        return "";
    auto iter = _curretnTags.begin();
    std::string name=*iter;
    ++iter;
    for(;iter!=_curretnTags.end();++iter){
        name.append(std::string("."+(*iter)));
    }
    return name;
}
std::vector<std::string> Attrs(std::string _str){
    std::vector<std::string> attrs;
    std::size_t begin =0;
    std::size_t end = 0;
    std::size_t endOfAttr =0;
    while(begin<_str.length()){
        end = _str.find_first_of('"',begin);
        if(end==std::string::npos)
            break;
        endOfAttr =_str.find_first_of('"',end+1);
        attrs.push_back(_str.substr(begin,endOfAttr+1-begin));
        begin = endOfAttr+1;

    }
    std::vector<std::string > tokens;
    for(auto _:attrs){
        split(_,tokens,'=');
    }
    return tokens;

}
void ParseSet(std::vector<std::string> &_str){
   TagAttrVal.clear();
   std::list<std::string> curretnTags;
    std::string currentTag="";
    bool calculateTagName=true;
    for(auto _:_str){
        if(!(_[0]=='<'&&_[1]=='/')){
            auto str = _.substr(1,_.length()-2);
            auto end = str.find_first_of(' ');
            std::string tagName= str.substr(0,end);
            curretnTags.push_back(tagName);
            str= str.substr(end+1);

            std::vector<std::string> tokens=Attrs(str);
            if(calculateTagName){
                 currentTag =GetTagName(curretnTags);
                calculateTagName =false;
            }
            else{
                if(!currentTag.empty())
                    currentTag+=".";
                currentTag +=tagName;
            }

            for(auto iter = tokens.begin();iter!=tokens.end();){
                auto nextIter= iter;
                nextIter++;
                if(nextIter!=tokens.end()){
                    Set(currentTag,trim(*iter),trim(*nextIter));
                }
                iter++;
                iter++;
            }
        }
        else{
            curretnTags.pop_back();
           currentTag="";
            calculateTagName=true;
        }
    }
}

void ParseQuery( std::vector<std::string> &_str){
    for(auto _:_str){
        std::vector<std::string>tokens;
        split(_,tokens,'~');
        std::string tag= tokens[0];
        std::string attr = tokens[1];
        auto iter = TagAttrVal.find(tag);
        if(iter==TagAttrVal.end()){
            std::cout<<"Not Found!\n";
        }
        else{
            auto iterAttr = iter->second.find(attr);
            if(iterAttr==iter->second.end()){
                std::cout<<"Not Found!\n";
            }
            else{
                std::cout<<iterAttr->second<<"\n";
            }

        }
    }
}
void printCode(){
    for(auto &_:TagAttrVal){
        std::cout<<_.first<<std::endl;
        for(auto &__:_.second){
            std::cout<<"\t"<<__.first<<" "<<__.second<<"\n";
        }
    }
}

int main() {
    // Enter your code here. Read input from STDIN. Print output to STDOUT
    std::cout.sync_with_stdio(false);
    std::size_t n,q;
    std::cin>>n>>q;
    std::vector<std::string> code,query;
    std::string temp;
    while(std::getline(std::cin,temp)){
        if(temp.empty())
            continue;
        if(n>0){
            code.push_back(temp);
            n--;
        }
        else{
            query.push_back(temp);
            q--;
        }
    }
    ParseSet(code);
    ParseQuery(query);
   // printCode();
    return 0;
}

*/
