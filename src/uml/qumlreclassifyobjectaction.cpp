/****************************************************************************
**
** Copyright (C) 2013 Sandro S. Andrade <sandroandrade@kde.org>
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtUml module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/
#include "qumlreclassifyobjectaction.h"

#include "private/qumlreclassifyobjectactionobject_p.h"

#include <QtUml/QUmlActivity>
#include <QtUml/QUmlActivityEdge>
#include <QtUml/QUmlActivityGroup>
#include <QtUml/QUmlActivityNode>
#include <QtUml/QUmlActivityPartition>
#include <QtUml/QUmlClassifier>
#include <QtUml/QUmlComment>
#include <QtUml/QUmlConstraint>
#include <QtUml/QUmlDependency>
#include <QtUml/QUmlElement>
#include <QtUml/QUmlExceptionHandler>
#include <QtUml/QUmlInputPin>
#include <QtUml/QUmlInterruptibleActivityRegion>
#include <QtUml/QUmlNamedElement>
#include <QtUml/QUmlNamespace>
#include <QtUml/QUmlOutputPin>
#include <QtUml/QUmlPackage>
#include <QtUml/QUmlRedefinableElement>
#include <QtUml/QUmlStringExpression>
#include <QtUml/QUmlStructuredActivityNode>

QT_BEGIN_NAMESPACE

/*!
    \class QUmlReclassifyObjectAction

    \inmodule QtUml

    \brief A reclassify object action is an action that changes which classifiers classify an object.
 */

/*!
    Creates a new QUmlReclassifyObjectAction. Also creates the corresponding QObject-based representation returned by asQModelingObject() if \a createQModelingObject is true.
*/
QUmlReclassifyObjectAction::QUmlReclassifyObjectAction(bool createQModelingObject) :
    _isReplaceAll(false),
    _object(0)
{
    if (createQModelingObject)
        _qModelingObject = qobject_cast<QModelingObject *>(new QUmlReclassifyObjectActionObject(this));
}

/*!
    Destroys the QUmlReclassifyObjectAction.
 */
QUmlReclassifyObjectAction::~QUmlReclassifyObjectAction()
{
    QModelingElement::deleteQModelingObject();
}

/*!
    Returns a deep-copied clone of the QUmlReclassifyObjectAction.
*/
QModelingElement *QUmlReclassifyObjectAction::clone() const
{
    QUmlReclassifyObjectAction *c = new QUmlReclassifyObjectAction;
    c->asQModelingObject()->setObjectName(this->asQModelingObject()->objectName());
    c->asQModelingObject()->setProperty("role", this->asQModelingObject()->property("role"));
    foreach (QUmlComment *element, ownedComments())
        c->addOwnedComment(dynamic_cast<QUmlComment *>(element->clone()));
    c->setName(name());
    if (nameExpression())
        c->setNameExpression(dynamic_cast<QUmlStringExpression *>(nameExpression()->clone()));
    c->setVisibility(visibility());
    c->setLeaf(isLeaf());
    foreach (QUmlExceptionHandler *element, handlers())
        c->addHandler(dynamic_cast<QUmlExceptionHandler *>(element->clone()));
    c->setLocallyReentrant(isLocallyReentrant());
    foreach (QUmlConstraint *element, localPostconditions())
        c->addLocalPostcondition(dynamic_cast<QUmlConstraint *>(element->clone()));
    foreach (QUmlConstraint *element, localPreconditions())
        c->addLocalPrecondition(dynamic_cast<QUmlConstraint *>(element->clone()));
    c->setReplaceAll(isReplaceAll());
    if (object())
        c->setObject(dynamic_cast<QUmlInputPin *>(object()->clone()));
    return c;
}

// OWNED ATTRIBUTES

/*!
    Specifies whether existing classifiers should be removed before adding the new classifiers.
 */
bool QUmlReclassifyObjectAction::isReplaceAll() const
{
    // This is a read-write property

    return _isReplaceAll;
}

/*!
    Adjusts isReplaceAll to \a isReplaceAll.
 */
void QUmlReclassifyObjectAction::setReplaceAll(bool isReplaceAll)
{
    // This is a read-write property

    if (_isReplaceAll != isReplaceAll) {
        _isReplaceAll = isReplaceAll;
        _qModelingObject->modifiedResettableProperties() << QStringLiteral("isReplaceAll");
    }
}

/*!
    A set of classifiers to be added to the classifiers of the object.

    \sa addNewClassifier(), removeNewClassifier()
 */
const QSet<QUmlClassifier *> QUmlReclassifyObjectAction::newClassifiers() const
{
    // This is a read-write association end

    return _newClassifiers;
}

/*!
    Adds \a newClassifier to newClassifiers.

    \sa newClassifiers(), removeNewClassifier()
 */
void QUmlReclassifyObjectAction::addNewClassifier(QUmlClassifier *newClassifier)
{
    // This is a read-write association end

    if (!_newClassifiers.contains(newClassifier)) {
        _newClassifiers.insert(newClassifier);
        if (newClassifier && newClassifier->asQModelingObject() && this->asQModelingObject())
            QObject::connect(newClassifier->asQModelingObject(), SIGNAL(destroyed(QObject*)), this->asQModelingObject(), SLOT(removeNewClassifier(QObject *)));
    }
}

/*!
    Removes \a newClassifier from newClassifiers.

    \sa newClassifiers(), addNewClassifier()
 */
void QUmlReclassifyObjectAction::removeNewClassifier(QUmlClassifier *newClassifier)
{
    // This is a read-write association end

    if (_newClassifiers.contains(newClassifier)) {
        _newClassifiers.remove(newClassifier);
    }
}

/*!
    Holds the object to be reclassified.

    \b {Subsetted property(ies):} QUmlAction::inputs().
 */
QUmlInputPin *QUmlReclassifyObjectAction::object() const
{
    // This is a read-write association end

    return _object;
}

/*!
    Adjusts object to \a object.
 */
void QUmlReclassifyObjectAction::setObject(QUmlInputPin *object)
{
    // This is a read-write association end

    if (_object != object) {
        // Adjust subsetted properties
        removeInput(_object);

        _object = object;
        if (object && object->asQModelingObject() && this->asQModelingObject())
            QObject::connect(object->asQModelingObject(), SIGNAL(destroyed()), this->asQModelingObject(), SLOT(setObject()));
        object->asQModelingObject()->setParent(this->asQModelingObject());

        // Adjust subsetted properties
        if (object) {
            addInput(object);
        }
    }
}

/*!
    A set of classifiers to be removed from the classifiers of the object.

    \sa addOldClassifier(), removeOldClassifier()
 */
const QSet<QUmlClassifier *> QUmlReclassifyObjectAction::oldClassifiers() const
{
    // This is a read-write association end

    return _oldClassifiers;
}

/*!
    Adds \a oldClassifier to oldClassifiers.

    \sa oldClassifiers(), removeOldClassifier()
 */
void QUmlReclassifyObjectAction::addOldClassifier(QUmlClassifier *oldClassifier)
{
    // This is a read-write association end

    if (!_oldClassifiers.contains(oldClassifier)) {
        _oldClassifiers.insert(oldClassifier);
        if (oldClassifier && oldClassifier->asQModelingObject() && this->asQModelingObject())
            QObject::connect(oldClassifier->asQModelingObject(), SIGNAL(destroyed(QObject*)), this->asQModelingObject(), SLOT(removeOldClassifier(QObject *)));
    }
}

/*!
    Removes \a oldClassifier from oldClassifiers.

    \sa oldClassifiers(), addOldClassifier()
 */
void QUmlReclassifyObjectAction::removeOldClassifier(QUmlClassifier *oldClassifier)
{
    // This is a read-write association end

    if (_oldClassifiers.contains(oldClassifier)) {
        _oldClassifiers.remove(oldClassifier);
    }
}

QT_END_NAMESPACE

