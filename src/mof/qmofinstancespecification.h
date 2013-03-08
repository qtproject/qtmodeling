/****************************************************************************
**
** Copyright (C) 2012 Sandro S. Andrade <sandroandrade@kde.org>
** Contact: http://www.qt-project.org/
**
** This file is part of the QtMof module of the Qt Toolkit.
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
#ifndef QMOFINSTANCESPECIFICATION_H
#define QMOFINSTANCESPECIFICATION_H

#include <QtMof/QtMofGlobal>

// Base class includes
#include <QtMof/QMofPackageableElement>

// Qt includes
#include <QtCore/QSet>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

QT_MODULE(QtMof)

// Forward decls for function parameters
class QMofClassifier;
class QMofSlot;
class QMofValueSpecification;

class QMofInstanceSpecificationPrivate;

class Q_MOF_EXPORT QMofInstanceSpecification : public QMofPackageableElement
{
    Q_OBJECT

    Q_PROPERTY(QSet<QMofClassifier *> classifiers READ classifiers)
    Q_PROPERTY(QMofValueSpecification * specification READ specification WRITE setSpecification)
    Q_PROPERTY(QSet<QMofSlot *> slots_ READ slots_)

    Q_DISABLE_COPY(QMofInstanceSpecification)
    Q_DECLARE_PRIVATE(QMofInstanceSpecification)

public:
    Q_INVOKABLE explicit QMofInstanceSpecification(QWrappedObject *wrapper = 0, QWrappedObject *parent = 0);
    virtual ~QMofInstanceSpecification();

    // Association ends from QMofInstanceSpecification
    Q_INVOKABLE QSet<QMofClassifier *> classifiers() const;
    Q_INVOKABLE void addClassifier(QMofClassifier *classifier);
    Q_INVOKABLE void removeClassifier(QMofClassifier *classifier);
    Q_INVOKABLE QMofValueSpecification *specification() const;
    Q_INVOKABLE void setSpecification(QMofValueSpecification *specification);
    Q_INVOKABLE QSet<QMofSlot *> slots_() const;
    Q_INVOKABLE void addSlot_(QMofSlot *slot_);
    Q_INVOKABLE void removeSlot_(QMofSlot *slot_);

    virtual void setPropertyData();

protected:
    explicit QMofInstanceSpecification(QMofInstanceSpecificationPrivate &dd, QWrappedObject *wrapper = 0, QWrappedObject *parent = 0);
};

QT_END_NAMESPACE

QT_END_HEADER

#endif // QMOFINSTANCESPECIFICATION_H

