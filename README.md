# Arudino-Control
아두이노 컨트롤과 관련해서 정리해두려고 만들어놓은 Repo
# 1. 아두이노와 컴퓨터 사이의 Serial 통신 
- Concept: 0,1번핀은 아두이노와 컴퓨터 통신에 사용하므로, 실질적으로 컴퓨터를 통해 아두이노로 명령을 내리기 위해선
Master-Slave 구조를 가져야함. 따라서, 두 개의 보드를 사용하는데 이 때 Uno의 Digital pin + Software Serial의 조합을 사용함.
- 1 폴더에 이를 테스트 해볼 수 있는 코드를 업로드. 
