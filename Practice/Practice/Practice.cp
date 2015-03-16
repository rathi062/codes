/*
 *  Practice.cp
 *  Practice
 *
 *  Created by mohit rathi on 22/09/14.
 *  Copyright (c) 2014 mohit rathi. All rights reserved.
 *
 */

#include "Practice.h"
#include "PracticePriv.h"

CFStringRef PracticeUUID(void)
{
	CPractice* theObj = new CPractice;
	return theObj->UUID();
}

CFStringRef CPractice::UUID()
{
	return CFSTR("0001020304050607");
}
