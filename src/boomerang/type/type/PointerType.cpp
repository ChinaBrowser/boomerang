#pragma region License
/*
 * This file is part of the Boomerang Decompiler.
 *
 * See the file "LICENSE.TERMS" for information on usage and
 * redistribution of this file, and for a DISCLAIMER OF ALL
 * WARRANTIES.
 */
#pragma endregion License
#include "PointerType.h"


#include "boomerang/util/Log.h"
#include "boomerang/type/type/VoidType.h"


PointerType::PointerType(SharedType p)
    : Type(ePointer)
{
    setPointsTo(p);
}


PointerType::~PointerType()
{
}


void PointerType::setPointsTo(SharedType p)
{
    // Can't point to self; impossible to compare, print, etc
    if (p.get() == this) {
        LOG_ERROR("Attempted to create pointer to self: %1", HostAddress(this).toString());
        points_to = VoidType::get();
        return;
    }

    points_to = p;
}


SharedType PointerType::clone() const
{
    return PointerType::get(points_to->clone());
}


size_t PointerType::getSize() const
{
    // points_to->getSize(); // yes, it was a good idea at the time
    return STD_SIZE;
}


static int pointerCompareNest = 0;

bool PointerType::operator==(const Type& other) const
{
    //    return other.isPointer() && (*points_to == *((PointerType&)other).points_to);
    if (!other.isPointer()) {
        return false;
    }

    if (++pointerCompareNest >= 20) {
        LOG_WARN("PointerType operator== nesting depth exceeded!");
        return true;
    }

    bool ret = (*points_to == *((PointerType&)other).points_to);
    pointerCompareNest--;
    return ret;
}


bool PointerType::operator<(const Type& other) const
{
    if (id < other.getId()) {
        return true;
    }

    if (id > other.getId()) {
        return false;
    }

    return(*points_to < *((PointerType&)other).points_to);
}


SharedExp PointerType::match(SharedType pattern)
{
    if (pattern->isPointer()) {
        LOG_VERBOSE("Got pointer match: %1 to %2", this->getCtype(), pattern->getCtype());
        return points_to->match(pattern->as<PointerType>()->getPointsTo());
    }

    return Type::match(pattern);
}


bool PointerType::pointsToAlpha() const
{
    // void* counts as alpha* (and may replace it soon)
    if (points_to->isVoid()) {
        return true;
    }

    if (!points_to->isNamed()) {
        return false;
    }

    return points_to->as<NamedType>()->getName().startsWith("alpha");
}


int PointerType::pointerDepth() const
{
    int  d  = 1;
    auto pt = points_to;

    while (pt->isPointer()) {
        pt = pt->as<PointerType>()->getPointsTo();
        d++;
    }

    return d;
}


SharedType PointerType::getFinalPointsTo() const
{
    SharedType pt = points_to;

    while (pt->isPointer()) {
        pt = pt->as<PointerType>()->getPointsTo();
    }

    return pt;
}


QString PointerType::getCtype(bool final) const
{
    QString s = points_to->getCtype(final);

    if (points_to->isPointer()) {
        s += "*";
    }
    else {
        s += " *";
    }

    return s; // memory..
}


std::shared_ptr<PointerType> PointerType::newPtrAlpha()
{
    return PointerType::get(NamedType::getAlpha());
}