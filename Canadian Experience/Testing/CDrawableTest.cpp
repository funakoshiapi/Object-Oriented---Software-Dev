#include "pch.h"
#include "CppUnitTest.h"
#include "Drawable.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Gdiplus;
namespace Testing
{
	class CDrawableMock : public CDrawable
	{
	public:
		CDrawableMock(const std::wstring name) : CDrawable(name) {}
		virtual void Draw(Gdiplus::Graphics *graphics) override {}
		virtual bool HitTest(Gdiplus::Point pos) override { return false; }

	};

	TEST_CLASS(CDrawableTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		TEST_METHOD(TestCDrawableConstructor)
		{
			CDrawableMock draw(L"drawable");
			Assert::AreEqual(std::wstring(L"drawable"), draw.GetName());
		}
		TEST_METHOD(TestCDrawableRotation)
		{
			CDrawableMock draw(L"drawable");
			Assert::AreEqual(draw.GetRotation(), 0, 0.00001);

			draw.SetRotation(10.65);

			Assert::AreEqual(draw.GetRotation(), 10.65, 0.00001);

		}
		TEST_METHOD(TestCActorPosition)
		{
			CDrawableMock draw(L"drawable");
			Assert::IsTrue(draw.GetPosition().Equals(Point(0, 0)));

			draw.SetPosition(Point(50, 100));

			Assert::IsTrue(draw.GetPosition().Equals(Point(50, 100)));
		}
		TEST_METHOD(TestCDrawableAssociation)
		{
			CDrawableMock body(L"Body");
			auto arm = std::make_shared<CDrawableMock>(L"Arm");
			auto leg = std::make_shared<CDrawableMock>(L"Leg");

			Assert::IsNull(arm->GetParent());
			Assert::IsNull(leg->GetParent());

			body.AddChild(arm);
			body.AddChild(leg);

			Assert::IsTrue(arm->GetParent() == &body);
			Assert::IsTrue(leg->GetParent() == &body);
		}
	};
}