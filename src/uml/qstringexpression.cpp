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

#include "qstringexpression.h"
#include "qstringexpression_p.h"

QT_BEGIN_NAMESPACE_QTUML

QStringExpressionPrivate::QStringExpressionPrivate() :
    owningExpression(0),
    subExpressions(new QSet<QStringExpression *>)
{
}

QStringExpressionPrivate::~QStringExpressionPrivate()
{
    delete subExpressions;
}

/*!
    \class QStringExpression

    \inmodule QtUml

    \brief An expression that specifies a string value that is derived by concatenating a set of sub string expressions, some of which might be template parameters.
 */

QStringExpression::QStringExpression(QtMof::QMofObject *parent, QtMof::QMofObject *wrapper) :
    QtMof::QMofObject(*new QStringExpressionPrivate, parent, wrapper),
    _wrappedExpression(new QExpression(this, this)),
    _wrappedTemplateableElement(new QTemplateableElement(this, this))
{
}

QStringExpression::QStringExpression(QStringExpressionPrivate &dd, QtMof::QMofObject *parent, QtMof::QMofObject *wrapper) :
    QtMof::QMofObject(dd, parent, wrapper),
    _wrappedExpression(new QExpression(this, this)),
    _wrappedTemplateableElement(new QTemplateableElement(this, this))
{
}

QStringExpression::~QStringExpression()
{
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM AGGREGATED QElement
// ---------------------------------------------------------------

/*!
    The Elements owned by this element.
 */
const QSet<QElement *> *QStringExpression::ownedElements() const
{
    return (qmofobject_cast<const QElement *>(this))->ownedElements();
}

/*!
    The Element that owns this element.
 */
QElement *QStringExpression::owner() const
{
    return (qmofobject_cast<const QElement *>(this))->owner();
}

/*!
    The Comments owned by this element.
 */
const QSet<QComment *> *QStringExpression::ownedComments() const
{
    return (qmofobject_cast<const QElement *>(this))->ownedComments();
}

void QStringExpression::addOwnedComment(QComment *ownedComment)
{
    (qmofobject_cast<QElement *>(this))->addOwnedComment(ownedComment);
}

void QStringExpression::removeOwnedComment(QComment *ownedComment)
{
    (qmofobject_cast<QElement *>(this))->removeOwnedComment(ownedComment);
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM AGGREGATED QTemplateableElement
// ---------------------------------------------------------------

/*!
    The optional template signature specifying the formal template parameters.
 */
QTemplateSignature *QStringExpression::ownedTemplateSignature() const
{
    return (qmofobject_cast<const QTemplateableElement *>(this))->ownedTemplateSignature();
}

void QStringExpression::setOwnedTemplateSignature(QTemplateSignature *ownedTemplateSignature)
{
    (qmofobject_cast<QTemplateableElement *>(this))->setOwnedTemplateSignature(ownedTemplateSignature);
}

/*!
    The optional bindings from this element to templates.
 */
const QSet<QTemplateBinding *> *QStringExpression::templateBindings() const
{
    return (qmofobject_cast<const QTemplateableElement *>(this))->templateBindings();
}

void QStringExpression::addTemplateBinding(QTemplateBinding *templateBinding)
{
    (qmofobject_cast<QTemplateableElement *>(this))->addTemplateBinding(templateBinding);
}

void QStringExpression::removeTemplateBinding(QTemplateBinding *templateBinding)
{
    (qmofobject_cast<QTemplateableElement *>(this))->removeTemplateBinding(templateBinding);
}

// ---------------------------------------------------------------
// ASSOCIATION ENDS FROM QStringExpression
// ---------------------------------------------------------------

/*!
    The string expression of which this expression is a substring.
 */
QStringExpression *QStringExpression::owningExpression() const
{
    // This is a read-write association end

    Q_D(const QStringExpression);
    return d->owningExpression;
}

void QStringExpression::setOwningExpression(QStringExpression *owningExpression)
{
    // This is a read-write association end

    Q_D(QStringExpression);
    if (d->owningExpression != owningExpression) {
        // Adjust opposite property
        if (d->owningExpression)
            d->owningExpression->removeSubExpression(this);

        d->owningExpression = owningExpression;

        // Adjust subsetted property(ies)
        (qmofobject_cast<QElementPrivate *>(d))->setOwner(qmofobject_cast<QElement *>(owningExpression));

        // Adjust opposite property
        if (owningExpression)
            owningExpression->addSubExpression(this);
    }
}

/*!
    The StringExpressions that constitute this StringExpression.
 */
const QSet<QStringExpression *> *QStringExpression::subExpressions() const
{
    // This is a read-write association end

    Q_D(const QStringExpression);
    return d->subExpressions;
}

void QStringExpression::addSubExpression(QStringExpression *subExpression)
{
    // This is a read-write association end

    Q_D(QStringExpression);
    if (!d->subExpressions->contains(subExpression)) {
        d->subExpressions->insert(subExpression);

        // Adjust subsetted property(ies)
        (qmofobject_cast<QElementPrivate *>(d))->addOwnedElement(qmofobject_cast<QElement *>(subExpression));

        // Adjust opposite property
        subExpression->setOwningExpression(this);
    }
}

void QStringExpression::removeSubExpression(QStringExpression *subExpression)
{
    // This is a read-write association end

    Q_D(QStringExpression);
    if (d->subExpressions->contains(subExpression)) {
        d->subExpressions->remove(subExpression);

        // Adjust subsetted property(ies)
        (qmofobject_cast<QElementPrivate *>(d))->removeOwnedElement(qmofobject_cast<QElement *>(subExpression));

        // Adjust opposite property
        subExpression->setOwningExpression(0);
    }
}

/*!
    The query stringValue() returns the string that concatenates, in order, all the component string literals of all the subexpressions that are part of the StringExpression.
 */
QString QStringExpression::stringValue() const
{
    qWarning("QStringExpression::stringValue: operation to be implemented");

    return QString(); // change here to your derived return
}

#include "moc_qstringexpression.cpp"

QT_END_NAMESPACE_QTUML

