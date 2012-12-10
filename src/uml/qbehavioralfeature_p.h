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
#ifndef QTUML_QBEHAVIORALFEATURE_P_H
#define QTUML_QBEHAVIORALFEATURE_P_H

// Base class includes
#include "private/qmofobject_p.h"
#include "private/qnamespace_p.h"
#include "private/qfeature_p.h"

#include "QtUml/QBehavioralFeature"

// QtUml includes
#include "QtUml/QtUmlEnumerations"

// Qt includes
#include "QtCore/QList"
#include "QtCore/QSet"

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE_QTUML

QT_MODULE(QtUml)

// Forward decls for function parameters
class QType;
class QNamedElement;
class QParameterSet;
class QBehavior;
class QParameter;

class Q_UML_EXPORT QBehavioralFeaturePrivate : public QtMof::QMofObjectPrivate
{
    Q_DECLARE_PUBLIC(QBehavioralFeature)

public:
    explicit QBehavioralFeaturePrivate();
    virtual ~QBehavioralFeaturePrivate();

    QtUml::CallConcurrencyKind concurrency;
    bool isAbstract;
    QSet<QType *> *raisedExceptions;
    QList<QParameter *> *ownedParameters;
    QSet<QParameterSet *> *ownedParameterSets;
    QSet<QBehavior *> *methods;
};

QT_END_NAMESPACE_QTUML

QT_END_HEADER

#endif // QTUML_QBEHAVIORALFEATURE_P_H

