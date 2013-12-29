/**
 * Licensed to Green Energy Corp (www.greenenergycorp.com) under one or
 * more contributor license agreements. See the NOTICE file distributed
 * with this work for additional information regarding copyright ownership.
 * Green Energy Corp licenses this file to you under the Apache License,
 * Version 2.0 (the "License"); you may not use this file except in
 * compliance with the License.  You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * This project was forked on 01/01/2013 by Automatak, LLC and modifications
 * may have been made to this file. Automatak, LLC licenses these modifications
 * to you under the terms of the License.
 */
#ifndef __DOWN_SAMPLING_H_
#define __DOWN_SAMPLING_H_

#include <opendnp3/Uncopyable.h>

#include <cstdint>

namespace opendnp3
{
	// A safe down sampling class
	template <class Source, class Target>
	class DownSampling : private Uncopyable
	{
		static const Target TARGET_MAX;
		static const Target TARGET_MIN;

		public:

		static bool Apply(Source src, Target& target)
		{
			if(src > TARGET_MAX)
			{
				target = TARGET_MAX;
				return true;
			}
			else if( src < TARGET_MIN)
			{
				target = TARGET_MIN;
				return true;
			}
			else
			{
				target = static_cast<Target>(src);
				return false;
			}
		}
	};

	template <class Source, class Target>
	const Target DownSampling<Source,Target>::TARGET_MAX(std::numeric_limits<Target>::max());
	
	template <class Source, class Target>
	const Target DownSampling<Source,Target>::TARGET_MIN(std::numeric_limits<Target>::min());
}

#endif