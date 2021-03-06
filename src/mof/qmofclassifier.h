/****************************************************************************
**
** Copyright (C) 2013 Sandro S. Andrade <sandroandrade@kde.org>
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtMof module of the Qt Toolkit.
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
#ifndef QMOFCLASSIFIER_H
#define QMOFCLASSIFIER_H

#include <QtMof/QtMofGlobal>

#include <QtMof/QMofType>
#include <QtMof/QMofRedefinableElement>
#include <QtMof/QMofNamespace>

QT_BEGIN_NAMESPACE

QT_MODULE(QtMof)

class QMofFeature;
class QMofGeneralization;
class QMofNamedElement;
class QMofProperty;

class Q_MOF_EXPORT QMofClassifier : public QMofType, public QMofRedefinableElement, public QMofNamespace
{
public:
    virtual ~QMofClassifier();

    Q_DECL_HIDDEN virtual QModelingElement *clone() const;

    // Owned attributes
    const QSet<QMofProperty *> attributes() const;
    Q_DECL_HIDDEN void addAttribute(QMofProperty *attribute);
    Q_DECL_HIDDEN void removeAttribute(QMofProperty *attribute);
    const QSet<QMofFeature *> features() const;
    Q_DECL_HIDDEN void addFeature(QMofFeature *feature);
    Q_DECL_HIDDEN void removeFeature(QMofFeature *feature);
    const QSet<QMofClassifier *> generals() const;
    void addGeneral(QMofClassifier *general);
    void removeGeneral(QMofClassifier *general);
    const QSet<QMofGeneralization *> generalizations() const;
    void addGeneralization(QMofGeneralization *generalization);
    void removeGeneralization(QMofGeneralization *generalization);
    const QSet<QMofNamedElement *> inheritedMembers() const;
    Q_DECL_HIDDEN void addInheritedMember(QMofNamedElement *inheritedMember);
    Q_DECL_HIDDEN void removeInheritedMember(QMofNamedElement *inheritedMember);
    bool isAbstract() const;
    void setAbstract(bool isAbstract);
    bool isFinalSpecialization() const;
    void setFinalSpecialization(bool isFinalSpecialization);
    const QSet<QMofClassifier *> redefinedClassifiers() const;
    void addRedefinedClassifier(QMofClassifier *redefinedClassifier);
    void removeRedefinedClassifier(QMofClassifier *redefinedClassifier);

    // Operations
    QSet<QMofFeature *> allFeatures() const;
    QSet<QMofClassifier *> allParents() const;
    bool conformsTo(QMofClassifier *other) const;
    bool hasVisibilityOf(QMofNamedElement *n) const;
    QSet<QMofNamedElement *> inherit(QSet<QMofNamedElement *> inhs) const;
    QSet<QMofNamedElement *> inheritableMembers(QMofClassifier *c) const;
    bool maySpecializeType(QMofClassifier *c) const;
    QSet<QMofClassifier *> parents() const;

protected:
    explicit QMofClassifier();

    QSet<QMofProperty *> _attributes;
    QSet<QMofFeature *> _features;
    QSet<QMofGeneralization *> _generalizations;
    bool _isAbstract;
    bool _isFinalSpecialization;
    QSet<QMofClassifier *> _redefinedClassifiers;
};

QT_END_NAMESPACE

Q_DECLARE_METATYPE(QT_PREPEND_NAMESPACE(QMofClassifier) *)

#endif // QMOFCLASSIFIER_H

