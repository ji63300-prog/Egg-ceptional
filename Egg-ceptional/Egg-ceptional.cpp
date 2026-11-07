
#include <iostream>
using namespace std;

class Egg {
protected:
    const string size;
    const string flavor;
public:
	Egg(string s, string f):
        size(s), flavor(f) {}

	string get_size() const {
		return size;
	}

	string get_flavor() const {
		return flavor;
	}

    virtual void eat_egg() = 0;
};

class Boiled : public Egg {
protected:
 public:
	Boiled(string s, string f) :
		Egg(s, f) {
	}

    void eat_egg() override {
		cout << "Eating a boiled egg of size " << size << " and flavor " << flavor << endl;
    }
};

class Scrambled : public Egg {
protected:
public:
	Scrambled(string s, string f) :
		Egg(s, f) {
	}

	void eat_egg() override {
		cout << "Eating a scrambled egg of size " << size << " and flavor " << flavor << endl;
	}
};

class bad_egg : public exception {};

class RottenEgg : public Egg {
public:
	RottenEgg(string s, string f)
		: Egg(s, f) {
	}

	void eat_egg() override {
		throw bad_egg();
	}
};

class Carton {
private:
    Egg* eggs[12];
    int count;

public:
    Carton() {
        count = 0;
    }

    void addEgg(Egg* egg) {
        if (count < 12) {
            eggs[count] = egg;
            count++;
        }
    }

    void eatEgg() {
        if (count == 0) {
            cout << "Carton is empty." << endl;
            return;
        }

        Egg* egg = eggs[--count];

        try {
            egg->eat_egg();
        }
        catch (bad_egg&) {
            cout << "This egg was rotten" << endl;
        }

        delete egg;
    }
};



int main()
{
	//Egg* egg1 = new Boiled("large", "salty");
	//Egg* egg2 = new Scrambled("medium", "spicy");
	//egg1->eat_egg();
	//egg2->eat_egg();

    Carton carton;

    carton.addEgg(new Boiled("large", "salty"));
    carton.addEgg(new Scrambled("medium", "spicy"));
    carton.addEgg(new RottenEgg("small", "gross"));

    carton.eatEgg();
    carton.eatEgg();
    carton.eatEgg();


}

