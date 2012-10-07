/****************************************************************************
**
** Copyright (C) 2012 Sandro S. Andrade <sandroandrade@kde.org>
** Contact: http://www.qt-project.org/
**
** This file is part of the QtUml module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "qliteralstring.h"


QT_BEGIN_NAMESPACE_QTUML

class QLiteralStringPrivate
{
public:
    explicit QLiteralStringPrivate();
    virtual ~QLiteralStringPrivate();

    QString value;
};

QLiteralStringPrivate::QLiteralStringPrivate()
{
}

QLiteralStringPrivate::~QLiteralStringPrivate()
{
}

/*!
    \class QLiteralString

    \inmodule QtUml

    \brief A literal string is a specification of a string value.
 */

QLiteralString::QLiteralString(QObject *parent)
    : QObject(parent), d_ptr(new QLiteralStringPrivate)
{
}

QLiteralString::~QLiteralString()
{
    delete d_ptr;
}

/*!
    The specified String value.
 */
QString QLiteralString::value() const
{
    return d_ptr->value;
}

void QLiteralString::setValue(QString value)
{
    d_ptr->value = value;
}

/*!
    The query isComputable() is redefined to be true.
 */
bool QLiteralString::isComputable() const
{
    qWarning("QLiteralString::isComputable: operation to be implemented");
}

/*!
    The query stringValue() gives the value.
 */
QString QLiteralString::stringValue() const
{
    qWarning("QLiteralString::stringValue: operation to be implemented");
}

#include "moc_qliteralstring.cpp"

QT_END_NAMESPACE_QTUML

