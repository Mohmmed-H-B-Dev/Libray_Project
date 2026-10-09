# 📚 نظام إدارة المكتبة والمخزون (C++) | Library & Inventory Management System

مشروع تطبيقي مكتوب بلغة **++C** يعتمد على البرمجة الكائنية (**OOP**)، تم إنشاؤه وتطويره كجزء من **خارطة التعلم والتدريب العملي** على مفاهيم البرمجة الكائنية وتصميم الأنظمة عبر واجهة السطر البرمجي (Console Application).

---

## 🎯 هدف المشروع

تم تطوير هذا المشروع للتدرب والتطبيق العملي على:
* **مفاهيم البرمجة الكائنية (OOP)**: التغليف (Encapsulation)، الوراثة (Inheritance)، وتعدد الأشكال (Polymorphism).
* **تطبيق عمليات CRUD الأساسية**: الإضافة (Create)، القراءة (Read)، التعديل (Update)، والحذف (Delete).
* **تصميم الأنظمة بطبقات مستقلة (Layered Architecture)**: فصل منطق العمل والكلاسات عن واجهات العرض والتفاعل مع المستخدم.

---

## 🌟 المميزات الأساسية

### 🔐 1. إدارة المستخدمين والصلاحيات (User Management)
* **نظام تسجيل الدخول**: التحقق من هوية المستخدم وكلمة المرور[span_0](start_span)[span_0](end_span).
* **نظام الصلاحيات**: تحديد مستويات الوصول للمشرفين والمستخدمين[span_1](start_span)[span_1](end_span).
* **عمليات CRUD للمستخدمين**:
  * 📋 عرض قائمة المستخدمين (Show User List)[span_2](start_span)[span_2](end_span)
  * ➕ إضافة مستخدم جديد (Add New User)[span_3](start_span)[span_3](end_span)
  * ✏️ تعديل بيانات مستخدم (Update User Info)[span_4](start_span)[span_4](end_span)
  * ❌ حذف مستخدم (Delete User)[span_5](start_span)[span_5](end_span)
  * 🔍 البحث عن مستخدم (Find User)[span_6](start_span)[span_6](end_span)

---

### 📦 2. إدارة المخزون والمنتجات (Inventory Management)
* **إدارة المنتجات والكتب**: إمكانية الإضافة والتعديل والحذف للأصناف[span_7](start_span)[span_7](end_span).
* **متابعة الكميات والأسعار**: تتبع أسعار المواد، الكميات المتاحة، والنسب الضريبية[span_8](start_span)[span_8](end_span).
* **سندات التحويل**: متابعة حركة الأذونات وسندات التحويل بين الأقسام[span_9](start_span)[span_9](end_span).

---

### 📖 3. إدارة المؤلفين والكتب (Author & Book Cataloging)
* **سجل المؤلفين**: إضافة وتعديل والبحث عن بيانات المؤلفين[span_10](start_span)[span_10](end_span).
* **سجل الكتب**: متابعة تفاصيل الكتب والطلبات المعلقة[span_11](start_span)[span_11](end_span).

---

### 💳 4. المبيعات والعمليات المالية (Sales & Transactions)
* **شاشة البيع (POS)**: إصدار الفواتير وإتمام عمليات البيع[span_12](start_span)[span_12](end_span)[span_13](start_span)[span_13](end_span).
* **الطلبات المعلقة**: متابعة وتجهيز طلبات العملاء المعلقة[span_14](start_span)[span_14](end_span).
* **سجل المعاملات**: تتبع العمليات المالية وسجلات البيع[span_15](start_span)[span_15](end_span).

---

## 🛠️ البنية البرمجية والتقنيات المستخدمة

* **اللغة**: ++C (Object-Oriented Programming)[span_16](start_span)[span_16](end_span)[span_17](start_span)[span_17](end_span).
* **الهيكلية البرمجية**:
  * **كلاسات البيانات والمنطق (Core Models)**: مثل `clsPerson`, `clsUser`, `clsClient`, `clsAuthor`, `clsBook`, `clsInvoice`, `clsItem`[span_18](start_span)[span_18](end_span)[span_19](start_span)[span_19](end_span).
  * **كلاسات الواجهات (UI Screens)**: كلاسات مستقلة لإدارة الشاشات والتفاعل مع المستخدم (مثل `clsAddNewUserScreen`, `clsUpdateUserScreen`, `clsLoginScreen`)[span_20](start_span)[span_20](end_span)[span_21](start_span)[span_21](end_span).
* **حفظ البيانات (Data Persistence)**: التخزين باستخدام الملفات النصية (`Users.txt`, `Items.txt`, `Authers.txt`, إلخ) لتأمين استمرارية البيانات[span_22](start_span)[span_22](end_span).

---

## 🚀 كيفية التشغيل

1. **المتطلبات**: بيئة Visual Studio (مع حزمة C++ Desktop Development) أو أي محرر يدعم ++C[span_23](start_span)[span_23](end_span).
2. **فتح المشروع**: قم بفتح ملف الحل `Libray_Project.sln` داخل Visual Studio[span_24](start_span)[span_24](end_span).
3. **البناء والتشغيل**: قم بعمل Build للمشروع ثم تشغيله (`Ctrl + F5`).
