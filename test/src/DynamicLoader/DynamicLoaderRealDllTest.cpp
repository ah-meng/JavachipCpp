//
// Created by JavaChip on 24. 10. 31.
//

#include <gtest/gtest.h>
#include <DynamicLoader/DynamicLoader.h>
#include "IEndpointProvider.h" // 인터페이스 정의

// DLL에서 불러올 함수 타입 정의
using CreateObjectFunc = IEndpointProvider* (*)();
using DeleteObjectFunc = void (*)(IEndpointProvider*);

TEST(DynamicLoaderRealDllTest, LoadAndUseRealDll) {

    EXPECT_THROW(DynamicLoader loader("missing.dll"), std::runtime_error);

    // DLL 파일 경로 설정
    const std::string dllPath = "libA.dll"; // 실제 DLL 경로로 변경하세요.

    // DynamicLoader로 DLL 로드
    DynamicLoader loader(dllPath);

    // create_object 함수 가져오기
    const auto create_object = loader.LoadFunction<CreateObjectFunc>("create_object");
    ASSERT_NE(create_object, nullptr) << "Failed to load create_object function.";

    // delete_object 함수 가져오기
    const auto delete_object = loader.LoadFunction<DeleteObjectFunc>("delete_object");
    ASSERT_NE(delete_object, nullptr) << "Failed to load delete_object function.";

    // 객체 생성
    IEndpointProvider* obj = create_object();
    ASSERT_NE(obj, nullptr) << "Failed to create IEndpointProvider object.";

    // 생성된 객체로부터 필요한 동작을 수행할 수 있는지 추가 테스트를 작성할 수 있습니다.
    // 예: obj->addEndpoint(...);

    // 객체 삭제
    delete_object(obj);
    SUCCEED() << "Successfully created and deleted IEndpointProvider object from DLL.";
}
