#pragma region License
/*
 * This file is part of the Boomerang Decompiler.
 *
 * See the file "LICENSE.TERMS" for information on usage and
 * redistribution of this file, and for a DISCLAIMER OF ALL
 * WARRANTIES.
 */
#pragma endregion License
#include "BBSimplifyPass.h"

#include "boomerang/db/BasicBlock.h"
#include "boomerang/db/proc/UserProc.h"


BBSimplifyPass::BBSimplifyPass()
    : IPass("BBSimplify", PassID::BBSimplify)
{
}


bool BBSimplifyPass::execute(UserProc *proc)
{
    for (BasicBlock *bb : *proc->getCFG()) {
        bb->simplify();
    }
    return true;
}
