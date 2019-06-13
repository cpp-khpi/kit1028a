using namespace std;

void useAutoPtr() {
	std::auto_ptr<Textbook> ptr1(new Textbook(100, 5));
	std::auto_ptr<Textbook> ptr2;

	ptr2 = ptr1;

	if (ptr1.get() != NULL) {
		cout << "P1: " << *ptr1 << endl;
	}
	cout << "P2: " << *ptr2 << endl;

}

void useUniquePtr() {
	unique_ptr<Textbook> textbook1(new Textbook(195, 3));
	unique_ptr<Textbook> textbook2;

	cout << "textbook1 is " << (static_cast<bool>(textbook1) ? "not null\n" : "null\n") << endl;
	cout << "textbook2 is " << (static_cast<bool>(textbook2) ? "not null\n" : "null\n") << endl;

	textbook2 = std::move(textbook1);

	cout << "Ownership transferred to textbook2" << endl << endl;

	cout << "textbook1 is " << (static_cast<bool>(textbook1) ? "not null\n" : "null\n") << endl;
	cout << "textbook2 is " << (static_cast<bool>(textbook2) ? "not null\n" : "null\n") << endl;

	auto array_work = make_unique<Textbook[]>(3);

	for (int i = 0; i < 3; i++) {
		cout << array_work[i];
	}

}

void useSharedPtr() {
	{	shared_ptr<Textbook> obj_test;
	{
		auto pointer1 = make_shared<Textbook>(60, 4);
		{
			obj_test = pointer1;
			auto pointer2 = pointer1;
			cout << "Amount of points to pointer1: " << pointer1.use_count() <<endl;
			cout << "Pointer2: " << *pointer2 << endl;

		}
		cout << endl << "Pointer1: " << *pointer1 << endl;
		cout << "Amount of points to pointer1: " << pointer1.use_count() << endl;
	}

	cout << "Pointer2: " << *obj_test << endl;
	}


	{
		weak_ptr<Textbook> pointer3;
		auto pointer1 = make_shared<Textbook>(100, 5);
		{
			auto pointer2 = pointer1;
			cout << "Amount of points to pointer1: " << pointer1.use_count() << endl;
			pointer3 = pointer1;
			cout << "Pointer2: " << *pointer2 << endl;

		}
		cout << endl << "Pointer1: " << *pointer1 << endl;
		cout << "Amount of points to pointer1: " << pointer1.use_count() << endl;
	}

}
