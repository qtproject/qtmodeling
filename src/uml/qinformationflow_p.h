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
#ifndef QTUML_QINFORMATIONFLOW_P_H
#define QTUML_QINFORMATIONFLOW_P_H

#include <QtUml/QtUmlGlobal>

// Base class includes

#include "qdirectedrelationship_p.h"

#include "qpackageableelement_p.h"

// Qt includes
#include <QtCore/QSet>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE_QTUML

QT_MODULE(QtUml)

class QConnector;
class QMessage;
class QActivityEdge;
class QNamedElement;
class QClassifier;
class QRelationship;

class QInformationFlowPrivate : public QDirectedRelationshipPrivate, public QPackageableElementPrivate
{
public:
    explicit QInformationFlowPrivate();
    virtual ~QInformationFlowPrivate();

    QSet<QNamedElement *> *informationTargets;
    QSet<QConnector *> *realizingConnectors;
    QSet<QClassifier *> *conveyed;
    QSet<QNamedElement *> *informationSources;
    QSet<QMessage *> *realizingMessages;
    QSet<QActivityEdge *> *realizingActivityEdges;
    QSet<QRelationship *> *realizations;

    // Association-ends
    void addInformationTarget(const QNamedElement *informationTarget);
    void removeInformationTarget(const QNamedElement *informationTarget);
    void addRealizingConnector(const QConnector *realizingConnector);
    void removeRealizingConnector(const QConnector *realizingConnector);
    void addConveyed(const QClassifier *conveyed);
    void removeConveyed(const QClassifier *conveyed);
    void addInformationSource(const QNamedElement *informationSource);
    void removeInformationSource(const QNamedElement *informationSource);
    void addRealizingMessage(const QMessage *realizingMessage);
    void removeRealizingMessage(const QMessage *realizingMessage);
    void addRealizingActivityEdge(const QActivityEdge *realizingActivityEdge);
    void removeRealizingActivityEdge(const QActivityEdge *realizingActivityEdge);
    void addRealization(const QRelationship *realization);
    void removeRealization(const QRelationship *realization);
};

QT_END_NAMESPACE_QTUML

QT_END_HEADER

#endif // QTUML_QINFORMATIONFLOW_P_H

