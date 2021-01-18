#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Spell { 
    private:
        string scrollName;
    public:
        Spell(): scrollName("") { }
        Spell(string name): scrollName(name) { }
        virtual ~Spell() { }
        string revealScrollName() {
            return scrollName;
        }
};

class Fireball : public Spell { 
    private: int power;
    public:
        Fireball(int power): power(power) { }
        void revealFirepower(){
            cout << "Fireball: " << power << endl;
        }
};

class Frostbite : public Spell {
    private: int power;
    public:
        Frostbite(int power): power(power) { }
        void revealFrostpower(){
            cout << "Frostbite: " << power << endl;
        }
};

class Thunderstorm : public Spell { 
    private: int power;
    public:
        Thunderstorm(int power): power(power) { }
        void revealThunderpower(){
            cout << "Thunderstorm: " << power << endl;
        }
};

class Waterbolt : public Spell { 
    private: int power;
    public:
        Waterbolt(int power): power(power) { }
        void revealWaterpower(){
            cout << "Waterbolt: " << power << endl;
        }
};

class SpellJournal {
    public:
        static string journal;
        static string read() {
            return journal;
        }
}; 
string SpellJournal::journal = "";

void counterspell(Spell *spell) {

		
    Fireball* p0=dynamic_cast<Fireball*>(spell);
    Frostbite* p1=dynamic_cast<Frostbite*>(spell);
    Waterbolt* p2=dynamic_cast<Waterbolt*>(spell);
    Thunderstorm* p3=dynamic_cast<Thunderstorm*>(spell);
    if(p0) {
        p0->revealFirepower();
    }
    else if(p1) {
        p1->revealFrostpower();
    }
    else if (p2){
        p2->revealWaterpower();
    }
    else if (p3){
        p3->revealThunderpower();
    } 
	else { 
	    string spl = spell->revealScrollName();
	    string jrl = SpellJournal::read();
	    int m=spl.length();
	    int n=jrl.length();
	    int arr[m+1][n+1]; 

	    // Longest Common Subsequence
	    for (int i=0;i<=m;i++) 
			arr[i][0]=0;
	    for (int j=0;j<=n;j++) 
			arr[0][j]=0;
	    for (int i=1;i<=m;i++) {
			for (int j=1;j<=n;j++) {
				if (spl[i-1] == jrl[j-1])
					arr[i][j]=arr[i-1][j-1]+1;
				else
					arr[i][j]=max(arr[i][j-1],arr[i-1][j]);
			}
	    }  
	    cout << arr[m][n] << endl; 
	}
}

class Wizard {
    public:
        Spell *cast() {
            Spell *spell;
            string s; cin >> s;
            int power; cin >> power;
            if(s == "fire") {
                spell = new Fireball(power);
            }
            else if(s == "frost") {
                spell = new Frostbite(power);
            }
            else if(s == "water") {
                spell = new Waterbolt(power);
            }
            else if(s == "thunder") {
                spell = new Thunderstorm(power);
            } 
            else {
                spell = new Spell(s);
                cin >> SpellJournal::journal;
            }
            return spell;
        }
};

int main() {
    int T;
    cin >> T;
    Wizard Arawn;
    while(T--) {
        Spell *spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
}
