#include <memory>
#include "IosPhone.h"

using std::auto_ptr;
using std::unique_ptr;
using std::move;
using std::shared_ptr;

int main()
{
	// Problem of copy.
	auto_ptr<IosPhone> autoPrtEx(new IosPhone);
	auto_ptr<IosPhone> copy1 = autoPrtEx;

	//After copy: uniq = nunllptr, copy - object.
	unique_ptr<IosPhone> uniqPtrEx(new IosPhone[6]);
	unique_ptr<IosPhone> copy2 = move(uniqPtrEx);

	//After copy: 1 IosPhone doesn't exist.
	shared_ptr<IosPhone> sharedPtrEx(new IosPhone);
	shared_ptr<IosPhone> copy3(new IosPhone[28]);
	sharedPtrEx = copy3;
	
}