##Crash Report for crash_example.c
#Error Message
Segmentation fault (core dumped)

#Description of Crash
Program has crashed due to an attempt to access invalid memory, causing a segmentation fault.

#Root Cause Analysis
In main we set nums = allocate_numbers(n) where n = 0. since n <= 0 this causes allocate_numbers to return NULL.
Note that no memory is allocated in the heap before the return. The program then tries to acces nums[0], which
is an invalid access because nums is a null-pointer.

#Suggested Fix
Check that nums is not null before attempting to access nums[0]. The following code would suffice.

if (!nums)
{
	printf("no numbers allocated\n");
	return(0);
}
