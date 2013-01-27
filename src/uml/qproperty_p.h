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
** rights. These rights are described in the Nokia  LGPL Exception
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
#ifndef QTUML_QPROPERTY_P_H
#define QTUML_QPROPERTY_P_H

// Base class includes
#include "private/qwrappedobject_p.h"
#include "private/qstructuralfeature_p.h"
#include "private/qconnectableelement_p.h"
#include "private/qdeploymenttarget_p.h"

#include "QtUml/QProperty"

// QtUml includes
#include "QtUml/QtUmlNamespace"

// Qt includes
#include "QtCore/QString"
#include "QtCore/QList"
#include "QtCore/QSet"

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE_QTUML

QT_MODULE(QtUml)

// Forward decls for function parameters
class QType;
class QInterface;
class QRedefinableElement;
class QParameterableElement;
class QValueSpecification;
class QDataType;
class QAssociation;
class QClass;
class QProperty;

class Q_UML_EXPORT QPropertyPrivate : public QWrappedObjectPrivate
{
    Q_DECLARE_PUBLIC(QProperty)

public:
    explicit QPropertyPrivate();
    virtual ~QPropertyPrivate();

    bool isDerived;
    bool isReadOnly;
    bool isID;
    bool isDerivedUnion;
    QtUml::AggregationKind aggregation;
    QSet<QProperty *> subsettedProperties;
    QAssociation *owningAssociation;
    QList<QProperty *> qualifiers;
    QValueSpecification *defaultValue;
    QClass *class_;
    QProperty *associationEnd;
    QDataType *datatype;
    QSet<QProperty *> redefinedProperties;
    QAssociation *association;
    QInterface *interface_;
};

QT_END_NAMESPACE_QTUML

QT_END_HEADER

#endif // QTUML_QPROPERTY_P_H

