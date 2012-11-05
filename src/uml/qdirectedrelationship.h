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
#ifndef QTUML_QDIRECTEDRELATIONSHIP_H
#define QTUML_QDIRECTEDRELATIONSHIP_H

#include <QtUml/QtUmlGlobal>

// Base class includes
#include <QtUml/QRelationship>

// Qt includes
#include <QtCore/QSet>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE_QTUML

QT_MODULE(QtUml)

// Forward decls for function parameters
class QElement;

class QDirectedRelationshipPrivate;

class Q_UML_EXPORT QDirectedRelationship : public QRelationship
{
    Q_OBJECT

    // From QDirectedRelationship
    Q_PROPERTY(const QSet<QElement *> * sources READ sources)
    Q_PROPERTY(const QSet<QElement *> * targets READ targets)

    Q_DISABLE_COPY(QDirectedRelationship)
    Q_DECLARE_PRIVATE(QDirectedRelationship)

public:
    explicit QDirectedRelationship(QObject *parent = 0);
    virtual ~QDirectedRelationship();

    // Association ends from QDirectedRelationship
    const QSet<QElement *> *sources() const;
    const QSet<QElement *> *targets() const;

protected:
    explicit QDirectedRelationship(QDirectedRelationshipPrivate &dd, QObject *parent = 0);
};

QT_END_NAMESPACE_QTUML

Q_DECLARE_METATYPE(QT_PREPEND_NAMESPACE_QTUML(QDirectedRelationship) *)
Q_DECLARE_METATYPE(QSet<QT_PREPEND_NAMESPACE_QTUML(QDirectedRelationship) *> *)
Q_DECLARE_METATYPE(QList<QT_PREPEND_NAMESPACE_QTUML(QDirectedRelationship) *> *)

QT_END_HEADER

#endif // QTUML_QDIRECTEDRELATIONSHIP_H

