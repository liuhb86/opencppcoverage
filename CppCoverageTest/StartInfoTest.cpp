#include "stdafx.h"

#include <boost/filesystem.hpp>

#include "CppCoverage/StartInfo.hpp"
#include "CppCoverage/CppCoverageException.hpp"

namespace cov = CppCoverage;
namespace fs = boost::filesystem;

namespace CppCoverageTest
{
	namespace
	{
		const std::string file = __FILE__;
		const std::wstring validFilename(file.begin(), file.end());
	}

	TEST(StartInfoTest, Constructor)
	{
		ASSERT_NO_THROW(cov::StartInfo s{ validFilename };);
	}

	TEST(StartInfoTest, ConstructorFileNotFound)
	{		
		ASSERT_THROW(cov::StartInfo s(L""), cov::CppCoverageException);
	}

	TEST(StartInfoTest, SetWorkingDirectoryNotExists)
	{
		cov::StartInfo s(validFilename);
		fs::path folder{ L"" };
		
		ASSERT_THROW(s.SetWorkingDirectory(folder), cov::CppCoverageException);
	}

	TEST(StartInfoTest, SetWorkingDirectoryExists)
	{
		cov::StartInfo s(validFilename);
		fs::path folder{ L"." };

		ASSERT_NO_THROW(s.SetWorkingDirectory(folder));
	}

}