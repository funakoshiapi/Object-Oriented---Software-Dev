#include "pch.h"
#include "CppUnitTest.h"
#include "Timeline.h"
#include "AnimChannelAngle.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	TEST_CLASS(CTimelineTest)
	{
	public:
		TEST_METHOD(TestCTimelineNumFrames)
		{

			CTimeline timeline;

			// Default value
			Assert::AreEqual(300, timeline.GetNumFrames());

			// Changed time
			timeline.SetNumFrames(9);
			Assert::AreEqual(9, timeline.GetNumFrames());
		}

		TEST_METHOD(TestCTimelineGetCurrentTime)
		{

			CTimeline timeline;

			// Default value
			Assert::AreEqual(double(0), timeline.GetCurrentTime());

			// Changed time
			timeline.SetCurrentTime(9);
			Assert::AreEqual(double(9), timeline.GetCurrentTime());
		}

		TEST_METHOD(TestCTimelineFrameRate)
		{
			CTimeline timeline;

			// Default value
			Assert::AreEqual(30, timeline.GetFrameRate());

			// Changed time
			timeline.SetFrameRate(9);
			Assert::AreEqual(9, timeline.GetFrameRate());
		}

		TEST_METHOD(TestCTimelineCurrentTime)
		{
			CTimeline timeline;

			Assert::AreEqual(0, timeline.GetCurrentTime(), 0.0001);

			timeline.SetCurrentTime(28.5);
			Assert::AreEqual(28.5, timeline.GetCurrentTime(), 0.0001);
		}

		TEST_METHOD(TestCTimelineGetDuration)
		{
			CTimeline timeline;

			// Default value
			Assert::AreEqual(10, timeline.GetDuration(), 0.0001);

			// Changed duration
			timeline.SetFrameRate(375);
			Assert::AreEqual(300.0 / 375.0, timeline.GetDuration(), 0.0001);

			timeline.SetNumFrames(789);

			Assert::AreEqual(789.0 / 375.0, timeline.GetDuration(), 0.0001);
		}

		TEST_METHOD(TestCTimelineGetCurrentFrame)
		{
			CTimeline timeline;

			// Default value
			Assert::AreEqual(0, timeline.GetCurrentFrame());

			// Changed time
			timeline.SetCurrentTime(9.27);
			Assert::AreEqual(278, timeline.GetCurrentFrame());
		}
		TEST_METHOD(TestCTimelineAdd)
		{
				CTimeline timeline;
				CAnimChannelAngle channel;

				timeline.AddChannel(&channel);
				Assert::IsTrue(&timeline == channel.GetTimeline());
			
		}
		
	};
}