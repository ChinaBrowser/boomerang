#pragma region License
/*
 * This file is part of the Boomerang Decompiler.
 *
 * See the file "LICENSE.TERMS" for information on usage and
 * redistribution of this file, and for a DISCLAIMER OF ALL
 * WARRANTIES.
 */
#pragma endregion License
#pragma once


#include "TestUtils.h"


class CompoundTypeTest : public BoomerangTest
{
    Q_OBJECT

private slots:
    void testConstruct();
    void testEquals();
    void testLess();
    void testGetCtype();
    void testIsSuperStructOf(); // testIsSuperStructOf / isSubStructOf
    void testMemberType();
    void testMemberName();
    void testMemberOffset();
    void testGetOffsetRemainder();
    void testIsCompatibleWith();
};
