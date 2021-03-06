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
#include "qumlconsiderignorefragment.h"

#include "private/qumlconsiderignorefragmentobject_p.h"

#include <QtUml/QUmlComment>
#include <QtUml/QUmlDependency>
#include <QtUml/QUmlElement>
#include <QtUml/QUmlGate>
#include <QtUml/QUmlGeneralOrdering>
#include <QtUml/QUmlInteraction>
#include <QtUml/QUmlInteractionOperand>
#include <QtUml/QUmlLifeline>
#include <QtUml/QUmlNamedElement>
#include <QtUml/QUmlNamespace>
#include <QtUml/QUmlPackage>
#include <QtUml/QUmlStringExpression>

QT_BEGIN_NAMESPACE

/*!
    \class QUmlConsiderIgnoreFragment

    \inmodule QtUml

    \brief A consider ignore fragment is a kind of combined fragment that is used for the consider and ignore cases, which require lists of pertinent messages to be specified.
 */

/*!
    Creates a new QUmlConsiderIgnoreFragment. Also creates the corresponding QObject-based representation returned by asQModelingObject() if \a createQModelingObject is true.
*/
QUmlConsiderIgnoreFragment::QUmlConsiderIgnoreFragment(bool createQModelingObject) :
    QUmlCombinedFragment(false)
{
    if (createQModelingObject)
        _qModelingObject = qobject_cast<QModelingObject *>(new QUmlConsiderIgnoreFragmentObject(this));
}

/*!
    Destroys the QUmlConsiderIgnoreFragment.
 */
QUmlConsiderIgnoreFragment::~QUmlConsiderIgnoreFragment()
{
    QModelingElement::deleteQModelingObject();
}

/*!
    Returns a deep-copied clone of the QUmlConsiderIgnoreFragment.
*/
QModelingElement *QUmlConsiderIgnoreFragment::clone() const
{
    QUmlConsiderIgnoreFragment *c = new QUmlConsiderIgnoreFragment;
    c->asQModelingObject()->setObjectName(this->asQModelingObject()->objectName());
    c->asQModelingObject()->setProperty("role", this->asQModelingObject()->property("role"));
    foreach (QUmlComment *element, ownedComments())
        c->addOwnedComment(dynamic_cast<QUmlComment *>(element->clone()));
    c->setName(name());
    if (nameExpression())
        c->setNameExpression(dynamic_cast<QUmlStringExpression *>(nameExpression()->clone()));
    c->setVisibility(visibility());
    foreach (QUmlGeneralOrdering *element, generalOrderings())
        c->addGeneralOrdering(dynamic_cast<QUmlGeneralOrdering *>(element->clone()));
    foreach (QUmlGate *element, cfragmentGates())
        c->addCfragmentGate(dynamic_cast<QUmlGate *>(element->clone()));
    c->setInteractionOperator(interactionOperator());
    foreach (QUmlInteractionOperand *element, operands())
        c->addOperand(dynamic_cast<QUmlInteractionOperand *>(element->clone()));
    return c;
}

// OWNED ATTRIBUTES

/*!
    The set of messages that apply to this fragment

    \sa addMessage(), removeMessage()
 */
const QSet<QUmlNamedElement *> QUmlConsiderIgnoreFragment::messages() const
{
    // This is a read-write association end

    return _messages;
}

/*!
    Adds \a message to messages.

    \sa messages(), removeMessage()
 */
void QUmlConsiderIgnoreFragment::addMessage(QUmlNamedElement *message)
{
    // This is a read-write association end

    if (!_messages.contains(message)) {
        _messages.insert(message);
        if (message && message->asQModelingObject() && this->asQModelingObject())
            QObject::connect(message->asQModelingObject(), SIGNAL(destroyed(QObject*)), this->asQModelingObject(), SLOT(removeMessage(QObject *)));
    }
}

/*!
    Removes \a message from messages.

    \sa messages(), addMessage()
 */
void QUmlConsiderIgnoreFragment::removeMessage(QUmlNamedElement *message)
{
    // This is a read-write association end

    if (_messages.contains(message)) {
        _messages.remove(message);
    }
}

QT_END_NAMESPACE

