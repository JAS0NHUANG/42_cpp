class Base {
};

class Derive : public Base {
};

class Another : public Base {
};

int main() {
	Base* a = new Base();
	Derive* b = new Derive();

	Derive* e = (Derive*)a;
	Another
}
