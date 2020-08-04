import static com.r3.build.BuildControl.killAllExistingBuildsForJob
@Library('corda-shared-build-pipeline-steps')
import static com.r3.build.BuildControl.killAllExistingBuildsForJob

killAllExistingBuildsForJob(env.JOB_NAME, env.BUILD_NUMBER.toInteger())

pipeline {
    agent { label 'linux1' }
    options {
        timestamps()
        timeout(time: 10, unit: 'HOURS')
    }


    stages {
        stage('Corda OS Linux One Test') {
            steps {
                sh "./gradlew clean test --info"
            }
        }
    }

    post {
        always {
            junit testResults: '**/build/test-results/**/*.xml', keepLongStdio: true, allowEmptyResults: true
        }
        cleanup {
            deleteDir() /* clean up our workspace */
        }
    }
}
