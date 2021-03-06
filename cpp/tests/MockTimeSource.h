
//
// Licensed to Green Energy Corp (www.greenenergycorp.com) under one or
// more contributor license agreements. See the NOTICE file distributed
// with this work for additional information regarding copyright ownership.
// Green Energy Corp licenses this file to you under the Apache License,
// Version 2.0 (the "License"); you may not use this file except in
// compliance with the License.  You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// This file was forked on 01/01/2013 by Automatak, LLC and modifications
// have been made to this file. Automatak, LLC licenses these modifications to
// you under the terms of the License.
//

#ifndef __MOCK_TIME_SOURCE_H_
#define __MOCK_TIME_SOURCE_H_

#include <opendnp3/ITimeSource.h>

namespace opendnp3
{

class MockMonotonicTimeSource : public IMonotonicTimeSource
{
public:	

	// Implement ITimeSource
	timer_clock::time_point Now() {
		return mTime;
	}	

	void SetTime(const timer_clock::time_point& arTime) {
		mTime = arTime;
	}

	void Advance(const std::chrono::system_clock::duration& arDuration);

	void SetToNow();

private:

	timer_clock::time_point mTime;
};

class MockTimeSource : public ITimeSource
{
public:	

	// Implement ITimeSource
	std::chrono::system_clock::time_point GetUTC() {
		return mTime;
	}

	std::chrono::system_clock GetTimeStampUTC();

	void SetTime(const std::chrono::system_clock::time_point& arTime) {
		mTime = arTime;
	}

	void Advance(const std::chrono::system_clock::duration& arDuration);
	void SetToNow();

private:

	std::chrono::system_clock::time_point mTime;
};

}

#endif

