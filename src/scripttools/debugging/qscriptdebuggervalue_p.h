/****************************************************************************
**
** Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtSCriptTools module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** No Commercial Usage
** This file contains pre-release code and may not be distributed.
** You may use this file in accordance with the terms and conditions
** contained in the Technology Preview License Agreement accompanying
** this package.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights.  These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** If you have questions regarding the use of this file, please contact
** Nokia at qt-info@nokia.com.
**
**
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QSCRIPTDEBUGGERVALUE_P_H
#define QSCRIPTDEBUGGERVALUE_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <QtCore/qobjectdefs.h>
#include <QtCore/private/qscopedpointer_p.h>
#include <QtCore/qlist.h>

QT_BEGIN_NAMESPACE

class QScriptValue;
class QScriptEngine;
class QDataStream;

class QScriptDebuggerValuePrivate;
class Q_AUTOTEST_EXPORT QScriptDebuggerValue
{
public:
    enum ValueType {
        NoValue,
        UndefinedValue,
        NullValue,
        BooleanValue,
        StringValue,
        NumberValue,
        ObjectValue
    };

    QScriptDebuggerValue();
    QScriptDebuggerValue(const QScriptValue &value);
    QScriptDebuggerValue(double value);
    QScriptDebuggerValue(bool value);
    QScriptDebuggerValue(const QString &value);
    QScriptDebuggerValue(qint64 objectId);
    QScriptDebuggerValue(ValueType type);
    QScriptDebuggerValue(const QScriptDebuggerValue &other);
    ~QScriptDebuggerValue();

    QScriptDebuggerValue &operator=(const QScriptDebuggerValue &other);

    ValueType type() const;

    double numberValue() const;
    bool booleanValue() const;
    QString stringValue() const;
    qint64 objectId() const;

    QScriptValue toScriptValue(QScriptEngine *engine) const;
    QString toString() const;

    bool operator==(const QScriptDebuggerValue &other) const;
    bool operator!=(const QScriptDebuggerValue &other) const;

private:
    QScopedSharedPointer<QScriptDebuggerValuePrivate> d_ptr;

    Q_DECLARE_PRIVATE(QScriptDebuggerValue)
};

typedef QList<QScriptDebuggerValue> QScriptDebuggerValueList;

Q_AUTOTEST_EXPORT QDataStream &operator<<(QDataStream &, const QScriptDebuggerValue &);
Q_AUTOTEST_EXPORT QDataStream &operator>>(QDataStream &, QScriptDebuggerValue &);

QT_END_NAMESPACE

#endif
